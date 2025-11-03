#================================================================
# [Dream Disk 25] - Engine
# ~/projects/Engine/CMakeLists.txt
#================================================================
set(TGT "DD25Engine")

project(${TGT} LANGUAGES C CXX)

set(INC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${TGT} SHARED)

#----------------------------------------------------------------
# Include target platform cmake files
#----------------------------------------------------------------
if      (DD25_TARGET_DREAMCAST)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/dreamcast.cmake")
elseif  (DD25_TARGET_WINDOWS)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/windows.cmake")
	target_compile_features(${TGT} PRIVATE c_std_17)
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
	PUBLIC
		${INC}
)

#----------------------------------------------------------------
# Source Files
#----------------------------------------------------------------
target_sources(${TGT}
	PRIVATE
		${SRC}/Engine.cpp
	PUBLIC
		FILE_SET HEADERS
		BASE_DIRS inc
		FILES
			${INC}/Engine/Engine.hh
)
