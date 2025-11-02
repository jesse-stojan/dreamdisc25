#================================================================
# windowz.cmake
#================================================================
set(CMAKE_SYSTEM_NAME Windows)

set(WIN32_WINNT_XP	    0x0501)
set(WIN32_WINNT_VISTA	0x0600)
set(WIN32_WINNT_WIN7	0x0601)
set(WIN32_WINNT_WIN8	0x0602)
set(WIN32_WINNT_WIN8_1	0x0603)
set(WIN32_WINNT_WIN10	0x0A00)
set(WIN32_WINNT_WIN11	0x0A00)

#enable_language(C)
#enable_language(CXX)

if (MSVC)
	if 		(MSVC_TOOLSET STREQUAL "v143")
		set(CMAKE_C_STANDARD 17)
		set(CMAKE_C_STANDARD_REQUIRED ON)
		set(CMAKE_C_EXTENSIONS OFF)
		set(CMAKE_CXX_STANDARD 20)
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
		set(CMAKE_CXX_EXTENSIONS OFF)

	elseif 	(MSVC_TOOLSET STREQUAL "v142")
		set(CMAKE_C_STANDARD 17)
		set(CMAKE_C_STANDARD_REQUIRED ON)
		set(CMAKE_C_EXTENSIONS OFF)
		set(CMAKE_CXX_STANDARD 20)
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
		set(CMAKE_CXX_EXTENSIONS OFF)

	elseif 	(MSVC_TOOLSET STREQUAL "v141")
		set(CMAKE_C_STANDARD 11)
		set(CMAKE_C_STANDARD_REQUIRED ON)
		set(CMAKE_C_EXTENSIONS OFF)
		set(CMAKE_CXX_STANDARD 17)
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
		set(CMAKE_CXX_EXTENSIONS OFF)

	elseif 	(MSVC_TOOLSET STREQUAL "v141_xp")
		set(CMAKE_C_STANDARD 11)
		set(CMAKE_C_STANDARD_REQUIRED ON)
		set(CMAKE_C_EXTENSIONS OFF)
		set(CMAKE_CXX_STANDARD 17)
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
		set(CMAKE_CXX_EXTENSIONS OFF)

	elseif 	(MSVC_TOOLSET STREQUAL "v140")
		set(CMAKE_C_STANDARD 99)
		set(CMAKE_C_STANDARD_REQUIRED ON)
		set(CMAKE_C_EXTENSIONS OFF)
		set(CMAKE_CXX_STANDARD 11)
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
		set(CMAKE_CXX_EXTENSIONS OFF)

	else()
		set(CMAKE_C_STANDARD 99)
		set(CMAKE_C_STANDARD_REQUIRED ON)
		set(CMAKE_C_EXTENSIONS OFF)
		set(CMAKE_CXX_STANDARD 11)
		set(CMAKE_CXX_STANDARD_REQUIRED ON)
		set(CMAKE_CXX_EXTENSIONS OFF)
	endif()
endif()

# #----------------------------------------------------------------
# # Force /std:c++latest, or /std:clatest on MSVC
# #----------------------------------------------------------------
# if (MSVC)
#	# Use latest preview C/C++ language modes
#	add_compile_options(
#		"$<$<COMPILE_LANGUAGE:C>:/std:clatest>"
#		"$<$<COMPILE_LANGUAGE:CXX>:/std:c++latest>"
#	)
# endif()

if		(DEFINED TARGET_WINDOWS_XP)
	set(WINDOWS_VERSION		${WIN32_WINNT_XP})
elseif	(DEFINED TARGET_WINDOWS_VISTA)
	set(WINDOWS_VERSION		${WIN32_WINNT_VISTA})
elseif	(DEFINED TARGET_WINDOWS_7)
	set(WINDOWS_VERSION		${WIN32_WINNT_WIN7})
elseif	(DEFINED TARGET_WINDOWS_8)
	set(WINDOWS_VERSION		${WIN32_WINNT_WIN8})
elseif	(DEFINED TARGET_WINDOWS_8_1)
	set(WINDOWS_VERSION		${WIN32_WINNT_WIN8_1})
elseif	(DEFINED TARGET_WINDOWS_10)
	set(WINDOWS_VERSION		${WIN32_WINNT_WIN10})
elseif	(DEFINED TARGET_WINDOWS_11)
	set(WINDOWS_VERSION		${WIN32_WINNT_WIN11}) # same SDK macro as Win10
else()
	set(WINDOWS_VERSION     0x0500)
endif()

add_compile_options(
	/Wall               # Warning Level
	/sdl                # Security Development Lifecycle recommended checks
	/MP                 # Multi-processor Compilation
	/Zc:__cplusplus     # Preprocessor __cplusplus output C++ language version (conformance)
	/Zc:preprocessor	# Use Standard Conforming Preprocessor (Yes, implied for C++11 or higher, we'll specify explicitly)
	/permissive-        # Conformance Mode
	/analyze:external-  # Disable Code Analysis for External Headers
	/JMC                # Just My Code Debugging (DEBUG ONLY)
	/Qpar				# Enable Parallel Code Generation
	/GR					# Enable Run-Time-Type-Information (RTTI)
	/GF					# Enable String Pooling
	/guard:cf			# Control Flow Guard
	/Ob2				# Inline Function Expansion (Any Suitable)
	#/RTC1				# [DEBUG ONLY] Basic Runtime Checks
	/FAcs				# Assembler Output (Assembly, Machine Code and Source)
	/Zc:__STDC__
	/Zc:throwingNew-
	/Zc:noexceptTypes
)

add_link_options(
	#/SUBSYSTEM:WINDOWS  # Suppress the Console, set SubSystem
	/NOLOGO             # Supress Startup Banner
	/LTCG:incremental	# Use Fast Link Time Code Generation
	/LARGEADDRESSAWARE	# For Windows XP/x86 targets, enable access to more than 2GB of RAM
	#/CETCOMPAT			# CRT Shadow Stack Compatible, Marks executable image as compatible with Control-flow Enforcement Technology (CET) Shadow Stack
)

add_compile_definitions(
	_WIN32_WINNT=${WINDOWS_VERSION}
	#WINVER=${WINDOWS_VERSION}
	NOMINMAX=1
	#WIN32_LEAN_AND_MEAN=1
	DD25_WINDOWS=1
	UNICODE=1
	_UNICODE=1
)
