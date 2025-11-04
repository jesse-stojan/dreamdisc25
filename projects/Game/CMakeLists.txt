#================================================================
# [Dream Disk 25] - Game
# ~/projects/Game/CMakeLists.txt
#================================================================
set(TGT "DD25Game")

project(${TGT} LANGUAGES C CXX)

set(INC ${CMAKE_CURRENT_SOURCE_DIR}/inc/Game)
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${TGT})

add_dependencies(${TGT} DD25Engine)

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

#----------------------------------------------------------------
# Include Directories
#----------------------------------------------------------------
target_include_directories(${TGT}
	PRIVATE
		${INC}
	PUBLIC
		${ENGINE_INCLUDE_DIR}
)

#----------------------------------------------------------------
# Header Files
#----------------------------------------------------------------
set(GAME_HEADERS
	${INC}/Game.hh
)

#----------------------------------------------------------------
# Source Files
#----------------------------------------------------------------
set(GAME_SOURCES
	${SRC}/Game.cpp
)

# filter: Projects
set_target_properties(${TGT}	PROPERTIES FOLDER "Projects")

# filter: Third-Party
# set_target_properties(SH4ZAM	PROPERTIES FOLDER "Third-Party")

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}/inc/Game
	PREFIX "Header Files"
	FILES
		${GAME_HEADERS}
)

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}/src
	PREFIX "Source Files"
	FILES
		${GAME_SOURCES}
)

#----------------------------------------------------------------
# Header Files
#----------------------------------------------------------------
target_sources(${TGT}
	PRIVATE
		${GAME_SOURCES}
		${GAME_HEADERS}
)

#----------------------------------------------------------------
# Link Libraries
#----------------------------------------------------------------
target_link_libraries(${TGT}
	PRIVATE
		DD25Engine
)

#----------------------------------------------------------------
# Game Assets
#----------------------------------------------------------------
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
