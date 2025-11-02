set(TGT "DD25Editor")

project(${TGT} LANGUAGES C CXX)

set(HDR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

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

add_executable(${TGT}
	${SRC_DIR}/Editor.cpp
)
