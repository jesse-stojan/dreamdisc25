#!NOTE: Requires Dreamcast toolchain (CMAKE_SYSTEM_NAME "Dreamcast").

#================================================================
# function: dreamcast_package(options)
# Helper to make Dreamcast images from a built ELF.
# Automatically generates the disc image to run on dreamcast
# using KallistiOS and GNUC Tools/Utilities.
#================================================================
function(dreamcast_package)
	set(options)
	set(oneValueArgs TARGET DISC_LABEL DATA_DIR IP_TEMPLATE)
	set(multiValueArgs EXTRA_FILES)
	cmake_parse_arguments(DC "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if (NOT DC_TARGET)
		message(FATAL_ERROR "dreamcast_package(): TARGET is required.")
	endif()
	if (NOT TARGET ${DC_TARGET})
		message(FATAL_ERROR "dreamcast_package(): Target '${DC_TARGET}' not found.")
	endif()

	#----------------------------------------------------------------
	# Tools
	#----------------------------------------------------------------
	find_program(SH_OBJCOPY     NAMES   sh-elf-objcopy objcopy REQUIRED)
	find_program(DC_SCRAMBLE    NAMES   scramble)
	find_program(DC_MAKEIP      NAMES   makeip)
	find_program(DC_MKISOFS     NAMES   mkisofs genisoimage xorriso)
	find_program(DC_CDI4DC      NAMES   cdi4dc)

	if (NOT DC_SCRAMBLE)
		message(STATUS "dreamcast_package: 'scramble' not found -> will skip scrambling (1ST_READ.BIN)")
	endif()
	if (NOT DC_MAKEIP)
		message(STATUS "dreamcast_package: 'makeip' not found -> will make ISO without IP.BIN (dev-loaders may still boot)")
	endif()

	#----------------------------------------------------------------
	# Names/paths
	#----------------------------------------------------------------
	if (NOT DC_DISC_LABEL)
		set(DC_DISC_LABEL "DD25GAME")
	endif()

	set(_elf        $<TARGET_FILE:${DC_TARGET}>)
	set(_outdir     ${CMAKE_CURRENT_BINARY_DIR}/dreamcast)
	set(_bin        ${_outdir}/${DC_TARGET}.bin)
	set(_scrbin     ${_outdir}/1ST_READ.BIN)
	set(_ipbin      ${_outdir}/IP.BIN)
	set(_isoroot    ${_outdir}/iso_root)
	set(_iso        ${_outdir}/${DC_TARGET}.iso)
	set(_cdi        ${_outdir}/${DC_TARGET}.cdi)

	file(MAKE_DIRECTORY ${_outdir})
	file(MAKE_DIRECTORY ${_isoroot})

	#----------------------------------------------------------------
	# .bin from .elf
	#----------------------------------------------------------------
	add_custom_command(
		OUTPUT  ${_bin}
		COMMAND ${CMAKE_COMMAND} -E make_directory ${_outdir}
		COMMAND ${SH_OBJCOPY} -O binary ${_elf} ${_bin}
		DEPENDS ${DC_TARGET}
		COMMENT "DC: objcopy ${DC_TARGET}.elf -> .bin"
		VERBATIM
	)

	#----------------------------------------------------------------
	# 1ST_READ.BIN (scrambled)
	#----------------------------------------------------------------
	if (DC_SCRAMBLE)
		add_custom_command(
			OUTPUT ${_scrbin}
			COMMAND ${DC_SCRAMBLE} ${_bin} ${_scrbin}
			DEPENDS ${_bin}
			COMMENT "DC: scramble -> 1ST_READ.BIN"
			VERBATIM
		)
		set(_bootfile ${_scrbin})
	else()
		# fall back to the raw .bin as the boot-file
		add_custom_command(
			OUTPUT ${_scrbin}
			COMMAND ${CMAKE_COMMAND} -E copy ${_bin} ${_scrbin}
			DEPENDS ${_bin}
			COMMENT "DC: scramble not found, copying .bin as 1ST_READ.BIN"
			VERBATIM
		)
		set(_bootfile ${_scrbin})
	endif()

	#----------------------------------------------------------------
	# IP.BIN
	#----------------------------------------------------------------
	set(_have_ip OFF)
	if (DC_MAKEIP)
		set(_iptmpl "${DC_IP_TEMPLATE}")
		if (NOT EXISTS "${_iptmpl}")
			set(_iptmpl "$ENV{KOS_BASE}/utils/makeip/IP.TMPL")
		endif()
		add_custom_command(
			OUTPUT ${_ipbin}
			COMMAND ${DC_MAKEIP} -b ${_bootfile} ${_ipbin} ${_iptmpl}
			DEPENDS ${_scrbin}
			COMMENT "DC: makeip -> IP.BIN"
			VERBATIM
		)
		set(_have_ip ON)
	endif()

	#----------------------------------------------------------------
	# ISO root staging
	#----------------------------------------------------------------
	# Copy boot and any content into iso root
	add_custom_command(
		OUTPUT ${_isoroot}/.stamp
		COMMAND ${CMAKE_COMMAND} -E make_directory ${_isoroot}
		COMMAND ${CMAKE_COMMAND} -E copy ${_scrbin} ${_isoroot}/1ST_READ.BIN
		COMMAND ${CMAKE_COMMAND} -E touch ${_isoroot}/.stamp
		DEPENDS ${_scrbin}
		COMMENT "DC: stage ISO root with 1ST_READ.BIN"
		VERBATIM
	)

	if (DC_DATA_DIR)
		add_custom_command(
			OUTPUT ${_isoroot}/.assets
			COMMAND ${CMAKE_COMMAND} -E copy_directory ${DC_DATA_DIR} ${_isoroot}/data
			COMMAND ${CMAKE_COMMAND} -E touch ${_isoroot}/.assets
			DEPENDS ${_isoroot}/.stamp
			COMMENT "DC: copy assets -> /data"
			VERBATIM
		)
		set(_iso_stage_deps ${_isoroot}/.assets)
	else()
		set(_iso_stage_deps ${_isoroot}/.stamp)
	endif()

	foreach(_f IN LISTS DC_EXTRA_FILES)
		get_filename_component(_base "${_f}" NAME)
		add_custom_command(
			OUTPUT ${_isoroot}/${_base}
			COMMAND ${CMAKE_COMMAND} -E copy ${_f} ${_isoroot}/${_base}
			DEPENDS ${_iso_stage_deps}
			COMMENT "DC: add ${_base} to image"
			VERBATIM
		)
		list(APPEND _iso_stage_deps ${_isoroot}/${_base})
	endforeach()

	#----------------------------------------------------------------
	# ISO
	#----------------------------------------------------------------
	if (DC_MKISOFS)
		if (_have_ip)
			set(_mkisofs_boot -G ${_ipbin})
			set(_iso_deps ${_iso_stage_deps} ${_ipbin})
		else()
			set(_mkisofs_boot "")
			set(_iso_deps ${_iso_stage_deps})
		endif()

		add_custom_command(
			OUTPUT ${_iso}
			COMMAND ${DC_MKISOFS} ${_mkisofs_boot} -l -J -R -V ${DC_DISC_LABEL} -o ${_iso} ${_isoroot}
			DEPENDS ${_iso_deps}
			COMMENT "DC: mkisofs -> ${DC_TARGET}.iso"
			VERBATIM
		)
	endif()

	#----------------------------------------------------------------
	# CDI
	#----------------------------------------------------------------
	if (DC_CDI4DC AND EXISTS ${_iso})
		add_custom_command(
			OUTPUT ${_cdi}
			COMMAND ${DC_CDI4DC} ${_iso} ${_cdi}
			DEPENDS ${_iso}
			COMMENT "DC: cdi4dc -> ${DC_TARGET}.cdi"
			VERBATIM
		)
	endif()

	#----------------------------------------------------------------
	# Aggregate targets
	#----------------------------------------------------------------
	add_custom_target(${DC_TARGET}-bin  DEPENDS ${_bin})
	add_custom_target(${DC_TARGET}-1st  DEPENDS ${_scrbin})

	if (DC_MKISOFS)
		add_custom_target(${DC_TARGET}-iso DEPENDS ${_iso})
	endif()
	if (DC_CDI4DC)
		add_custom_target(${DC_TARGET}-cdi DEPENDS ${_cdi})
	endif()

	#----------------------------------------------------------------
	# STATUS OUTPUT MESSAGES
	#----------------------------------------------------------------
	message(STATUS "Dreamcast packaging for '${DC_TARGET}':")
	message(STATUS "    BIN: ${_bin}")
	message(STATUS "    1ST_READ.BIN: ${_scrbin}")
	if (DC_MAKEIP)
		message(STATUS "    IP.BIN: ${_ipbin}")
	endif()
	if (DC_MKISOFS)
		message(STATUS "    ISO: ${_iso}")
	endif()
	if (DC_CDI4DC)
		message(STATUS "    CDI: ${_cdi}")
	endif()
endfunction()
