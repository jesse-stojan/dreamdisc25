cmake_minimum_required(VERSION 3.31)

set(SHZ_VERSION_MAJOR 0)
set(SHZ_VERSION_MINOR 0)
set(SHZ_VERSION_PATCH 0)
set(SHZ_VERSION ${SHZ_VERSION_MAJOR}.${SHZ_VERSION_MINOR}.${SHZ_VERSION_PATCH})

project(sh4zam
    VERSION         ${SHZ_VERSION}
    DESCRIPTION     "Fast math library for the Sega Dreamcast's SH4 CPU"
    HOMEPAGE_URL    "sh4zam.falcogirgis.com"
    LANGUAGES       ASM C CXX
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(SHZ_SOURCES
    src/shz_circle.c
    src/shz_mem.s
    src/shz_xmtrx.c
    src/shz_xmtrx.s
    src/shz_quat.c
)

set(SHZ_INCLUDES
    inc/sh4zam/shz_cdefs.h
    inc/sh4zam/shz_cdefs.hpp
    inc/sh4zam/shz_circle.h
    inc/sh4zam/shz_circle.hpp
    inc/sh4zam/shz_trig.h
    inc/sh4zam/shz_trig.hpp
    inc/sh4zam/shz_trig.inl.h
    inc/sh4zam/shz_scalar.h
    inc/sh4zam/shz_scalar.hpp
    inc/sh4zam/shz_scalar.inl.h
    inc/sh4zam/shz_vector.h
    inc/sh4zam/shz_vector.hpp
    inc/sh4zam/shz_vector.inl.h
    inc/sh4zam/shz_xmtrx.h
    inc/sh4zam/shz_xmtrx.hpp
    inc/sh4zam/shz_xmtrx.inl.h
    inc/sh4zam/shz_matrix.h
    inc/sh4zam/shz_matrix.hpp
    inc/sh4zam/shz_matrix.inl.h
    inc/sh4zam/shz_quat.h
    inc/sh4zam/shz_quat.hpp
    inc/sh4zam/shz_quat.inl.h
    inc/sh4zam/shz_mem.h
    inc/sh4zam/shz_mem.hpp
    inc/sh4zam/shz_mem.inl.h
    inc/sh4zam/shz_fpscr.h
    inc/sh4zam/shz_sh4zam.h
    inc/sh4zam/shz_sh4zam.hpp
)

add_library(sh4zam STATIC ${SHZ_SOURCES})

set_target_properties(sh4zam PROPERTIES
    PUBLIC_HEADER "${SHZ_INCLUDES}"
)

target_compile_definitions(sh4zam 
    PUBLIC
        -DSHZ_VERSION_MAJOR=${SHZ_VERSION_MAJOR}
        -DSHZ_VERSION_MINOR=${SHZ_VERSION_MINOR}
        -DSHZ_VERSION_PATCH=${SHZ_VERSION_PATCH}
        -DSHZ_VERSION="${SHZ_VERSION}"
)

target_include_directories(sh4zam
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

install(TARGETS sh4zam
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sh4zam
)

option(SHZ_ENABLE_TESTS "Enable SH4ZAM Unit Tests" OFF)

if(SHZ_ENABLE_TESTS)
    add_subdirectory(test)
endif(SHZ_ENABLE_TESTS)
