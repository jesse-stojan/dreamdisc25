set(TGT "DD25Game")

project(${TGT} LANGUAGES C CXX)

set(HDR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#----------------------------------------------------------------
# Include target platform cmake files
#----------------------------------------------------------------
if      (DD25_TARGET_DREAMCAST)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/dreamcast.cmake")
elseif  (DD25_TARGET_WINDOWS)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/windows.cmake")
elseif  (DD25_TARGET_OSX)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/osx.cmake")
elseif  (DD25_TARGET_LINUX)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/linux.cmake")
elseif  (DD25_TARGET_BSD)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/bsd.cmake")
endif()

add_executable(${TGT}
	${SRC_DIR}/Game.cpp
)

if (DEFINED DREAMCAST OR CMAKE_SYSTEM_NAME STREQUAL "Dreamcast")
	include(${CMAKE_SOURCE_DIR}/cmake/dreamcast/dc-package.cmake)

	# Optional: point to your game assets to be baked into the disc image
	set(DD25_GAME_ASSETS ${CMAKE_SOURCE_DIR}/assets)

	dreamcast_package(
		TARGET      DD25Game
		DISC_LABEL  "DD25GAME"
		DATA_DIR    ${DD25_GAME_ASSETS}         # omit if you don’t want assets copied
		# IP_TEMPLATE ${CMAKE_SOURCE_DIR}/dist/IP.TMPL  # provide if you have a custom one
		# EXTRA_FILES ${CMAKE_SOURCE_DIR}/README.TXT    # any extra top-level files
	)
endif()
