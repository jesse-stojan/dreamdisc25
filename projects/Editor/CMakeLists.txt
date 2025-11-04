#================================================================
# [Dream Disk 25] - Editor
# ~/projects/Editor/CMakeLists.txt
#================================================================
set(TGT "DD25Editor")

project(${TGT} LANGUAGES C CXX)

set(INC ${CMAKE_CURRENT_SOURCE_DIR}/inc/Editor)
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(${TGT})

add_dependencies(${TGT} DD25Engine)

#----------------------------------------------------------------
# Include target platform cmake files
#----------------------------------------------------------------
if      (DD25_TARGET_WINDOWS)
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
set(EDITOR_HEADERS
	${INC}/Editor.hh
)

#----------------------------------------------------------------
# Source Files
#----------------------------------------------------------------
set(EDITOR_SOURCES
	${SRC}/Editor.cpp
)

# filter: Projects
set_target_properties(${TGT} PROPERTIES FOLDER "Projects")

# filter: Third-Party
# set_target_properties(SH4ZAM	PROPERTIES FOLDER "Third-Party")

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}/inc/Editor
	PREFIX "Header Files"
	FILES
		${EDITOR_HEADERS}
)

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}/src
	PREFIX "Source Files"
	FILES
		${EDITOR_SOURCES}
)

#----------------------------------------------------------------
# Header Files
#----------------------------------------------------------------
target_sources(${TGT}
	PRIVATE
		${EDITOR_SOURCES}
		${EDITOR_HEADERS}
)

#----------------------------------------------------------------
# Link Libraries
#----------------------------------------------------------------
target_link_libraries(${TGT}
	PRIVATE
		DD25Engine
)
