#================================================================
# bsd.cmake
#================================================================
set(CMAKE_SYSTEM_NAME	FreeBSD)

set(CMAKE_C_STANDARD			17)
set(CMAKE_C_STANDARD_REQUIRED	ON)
set(CMAKE_C_EXTENSIONS			OFF)

set(CMAKE_CXX_STANDARD			20)
set(CMAKE_CXX_STANDARD_REQUIRED	ON)
set(CMAKE_CXX_EXTENSIONS		OFF)

add_compile_definitions(
	DD25_FREEBSD=1
)

# target_link_libraries(foo PRIVATE GL X11 pthread)
