#================================================================
# [Dream Disk 25]
# ~/CMakeLists.txt
#================================================================
cmake_minimum_required(VERSION 3.31)

if (NOT CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL CMAKE_SYSTEM_PROCESSOR
	OR NOT CMAKE_HOST_SYSTEM STREQUAL CMAKE_SYSTEM)
	#TODO: Double check this shit works
	set(CROSS_FORCE TRUE)
endif()

#----------------------------------------------------------------
# Root Project
#----------------------------------------------------------------
project(DreamDisk25 LANGUAGES C CXX
	VERSION 0.0.1
)

# #----------------------------------------------------------------
# # Global language config
# #----------------------------------------------------------------
# set(CMAKE_C_STANDARD			17)
# set(CMAKE_C_STANDARD_REQUIRED	ON)
# set(CMAKE_C_EXTENSIONS			OFF)

# set(CMAKE_CXX_STANDARD			20)
# set(CMAKE_CXX_STANDARD_REQUIRED	ON)
# set(CMAKE_CXX_EXTENSIONS		OFF)

#----------------------------------------------------------------
# Sub-Projects to include (defaults)
#----------------------------------------------------------------
option(DD25_BUILD_ENGINE		"Build the Engine library"		ON)
option(DD25_BUILD_GAME			"Build the Game executable"		ON)
option(DD25_BUILD_EDITOR		"Build the Editor executable"	ON)

#----------------------------------------------------------------
# If Drmcsat or no :mink:
#----------------------------------------------------------------
if (DEFINED DREAMCAST OR CMAKE_SYSTEM_NAME STREQUAL "Dreamcast")
	set(DD25_PLATFORM_DREAMCAST TRUE)
else()
	set(DD25_PLATFORM_DREAMCAST FALSE)
endif()

#----------------------------------------------------------------
# [Desktop] Targets: Windows, macOS, Linux, and FreeBSD
#----------------------------------------------------------------
set(DD25_PLATFORM_DESKTOP FALSE)
if (NOT DD25_PLATFORM_DREAMCAST)
	if (WIN32 OR APPLE OR UNIX)
		set(DD25_PLATFORM_DESKTOP TRUE)
	endif()
endif()

if (${DD25_BUILD_EDITOR} AND ${DD25_PLATFORM_DESKTOP})
	set(DD25_BUILD_EDITOR ON)
else()
	set(DD25_BUILD_EDITOR OFF)
endif()

#----------------------------------------------------------------
# Folders for IDEs
#----------------------------------------------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

#----------------------------------------------------------------
# Include target cmake toolchain files
#----------------------------------------------------------------
if (NOT DEFINED CMAKE_TOOLCHAIN_FILE)
	if      (DD25_TARGET_DREAMCAST)
		include("${CMAKE_CURRENT_LIST_DIR}/cmake/toolchains/dreamcast.cmake")
	elseif  (DD25_TARGET_WINDOWS)
		include("${CMAKE_CURRENT_LIST_DIR}/cmake/toolchains/windows.cmake")
	elseif  (DD25_TARGET_OSX)
		include("${CMAKE_CURRENT_LIST_DIR}/cmake/toolchains/osx.cmake")
	elseif  (DD25_TARGET_LINUX)
		include("${CMAKE_CURRENT_LIST_DIR}/cmake/toolchains/linux.cmake")
	elseif  (DD25_TARGET_BSD)
		include("${CMAKE_CURRENT_LIST_DIR}/cmake/toolchains/bsd.cmake")
	endif()
endif()

#----------------------------------------------------------------
# Third-party Libraries
#----------------------------------------------------------------
#if(DD25_BUILD_ENGINE)
#   # [Engine only]
#	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/third-party/sh4zam)
#endif()

#----------------------------------------------------------------
# Projects
#----------------------------------------------------------------

set(ENGINE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/projects/Engine/inc)

# Engine [Dreamcast & Desktop]
if (DD25_BUILD_ENGINE)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/Engine)
endif()

# Game [Dreamcast & Desktop]
if (DD25_BUILD_GAME)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/Game)
endif()

# Editor [Desktop only]
if (DD25_BUILD_EDITOR AND DD25_PLATFORM_DESKTOP)
	add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/Editor)
endif()

#----------------------------------------------------------------
# Config Summary
#----------------------------------------------------------------
message(STATUS "========[ Dream Disk 2025 Build Config ]========")
message(STATUS "Dreamcast toolchain:    ${DD25_PLATFORM_DREAMCAST}")
message(STATUS "Desktop platform:       ${DD25_PLATFORM_DESKTOP}")
message(STATUS "Build Engine:           ${DD25_BUILD_ENGINE}")
message(STATUS "Build Game:             ${DD25_BUILD_GAME}")
message(STATUS "Build Editor:           ${DD25_BUILD_EDITOR}")
message(STATUS "Project Version:        ${CMAKE_PROJECT_VERSION}")
#TODO: Add more output, look like 11x engr. :cooldoge:
