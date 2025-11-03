#================================================================
# [Dream Disk 25] - Editor
# ~/projects/Editor/CMakeLists.txt
#================================================================
set(TGT "DD25Editor")

project(${TGT} LANGUAGES C CXX)

set(INC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${TGT})

#----------------------------------------------------------------
# Include target platform cmake files
#----------------------------------------------------------------
if      (DD25_TARGET_WINDOWS)
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
	PRIVATE
		${INC}
	PUBLIC
		${ENGINE_INCLUDE_DIR}
)

#----------------------------------------------------------------
# Header Files
#----------------------------------------------------------------
target_sources(${TGT}
	PRIVATE
		${SRC}/Editor.cpp
	PRIVATE
		${INC}/Editor/Editor.hh
)

#----------------------------------------------------------------
# Link Libraries
#----------------------------------------------------------------
target_link_libraries(${TGT}
	PRIVATE
		Engine
)
