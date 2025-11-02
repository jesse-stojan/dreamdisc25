#================================================================
# dreamcast.cmake
#================================================================

#----------------------------------------------------------------
# System Name and Architecture
#----------------------------------------------------------------
set(CMAKE_SYSTEM_NAME			Dreamcast)
set(CMAKE_SYSTEM_PROCESSOR		sh4)

# Cross-Compiling, don’t execute test codes? Idfk, sh4zam this shit
set(CMAKE_TRY_COMPILE_TARGET_TYPE		STATIC_LIBRARY)

#----------------------------------------------------------------
# Compiler/Linkers/Shit (GCC/G++ 15.2.0 from KOS)
#----------------------------------------------------------------
if (NOT DEFINED CMAKE_C_COMPILER)
	set(CMAKE_C_COMPILER		sh-elf-gcc)
endif()
if (NOT DEFINED CMAKE_CXX_COMPILER)
	set(CMAKE_CXX_COMPILER		sh-elf-g++)
endif()
if (NOT DEFINED CMAKE_ASM_COMPILER)
	set(CMAKE_ASM_COMPILER		sh-elf-gcc)
endif()
if (NOT DEFINED CMAKE_AR)
	set(CMAKE_AR				sh-elf-ar CACHE FILEPATH "" FORCE)
endif()
if (NOT DEFINED CMAKE_RANLIB)
	set(CMAKE_RANLIB			sh-elf-ranlib CACHE FILEPATH "" FORCE)
endif()
if (NOT DEFINED CMAKE_OBJCOPY)
	set(CMAKE_OBJCOPY			sh-elf-objcopy CACHE FILEPATH "" FORCE)
endif()
if (NOT DEFINED CMAKE_STRIP)
	set(CMAKE_STRIP				sh-elf-strip CACHE FILEPATH "" FORCE)
endif()

## kos_tools.cmake
#set(CMAKE_C_COMPILER   sh-elf-gcc)
#set(CMAKE_CXX_COMPILER sh-elf-g++)
#set(CMAKE_AR           sh-elf-ar)
#set(CMAKE_RANLIB       sh-elf-ranlib)
#set(CMAKE_OBJCOPY      sh-elf-objcopy)
#set(CMAKE_STRIP        sh-elf-strip)

#----------------------------------------------------------------
# Produce .elf by default; package into (.bin/.cdi) later
#----------------------------------------------------------------
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

#----------------------------------------------------------------
# C/C++ Versions (sh4zam uses C23/C++23)
#----------------------------------------------------------------
set(CMAKE_C_STANDARD			23)
set(CMAKE_C_STANDARD_REQUIRED	ON)
set(CMAKE_C_EXTENSIONS			OFF)

set(CMAKE_CXX_STANDARD			23)
set(CMAKE_CXX_STANDARD_REQUIRED	ON)
set(CMAKE_CXX_EXTENSIONS		OFF)

#----------------------------------------------------------------
# Add Compiler Definitions
#----------------------------------------------------------------
add_compile_definitions(
	DD25_DREAMCAST=1
)

#----------------------------------------------------------------
# KOS includes/libs
#----------------------------------------------------------------
if (NOT DEFINED ENV{KOS_BASE})
	message(FATAL_ERROR "KOS_BASE is not set in the environment.")
endif()

# CMake root search paths for headers/libs
set(CMAKE_SYSROOT "$ENV{KOS_BASE}")
set(CMAKE_FIND_ROOT_PATH
	"$ENV{KOS_BASE}"
	"$ENV{KOS_BASE}/../kos-ports"
	"$ENV{KOS_PORTS}"
)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# KOS include dirs
set(DC_KOS_INCLUDE_DIRS
	$ENV{KOS_BASE}/include
	$ENV{KOS_BASE}/kernel/arch/dreamcast/include
)

# Libraries. KOS (libkallisti)
set(DC_KOS_LIBRARY_DIRS
	$ENV{KOS_BASE}/lib
)

# KOS linker script
if (NOT DEFINED KOS_LINKER_SCRIPT)
	set(KOS_LINKER_SCRIPT $ENV{KOS_BASE}/utils/linkscripts/shlelf.xc CACHE FILEPATH "KOS linker script")
endif()

#----------------------------------------------------------------
# Architecture/Optimization flags
#----------------------------------------------------------------
# SH-4 little-endian, single-precision FPU, section gc, and no exceptions by default
set(DC_COMMON_CFLAGS	"-ml -m4 -m4-single-only -ffunction-sections -fdata-sections -fomit-frame-pointer -fno-asynchronous-unwind-tables")
set(DC_CFLAGS			"${DC_COMMON_CFLAGS} -O3")
set(DC_CXXFLAGS			"${DC_COMMON_CFLAGS} -O3 -fno-exceptions -fno-rtti")
# Apply
string(APPEND CMAKE_C_FLAGS_INIT	" ${DC_CFLAGS}")
string(APPEND CMAKE_CXX_FLAGS_INIT	" ${DC_CXXFLAGS}")

#----------------------------------------------------------------
# Linker: Uses KOS Script and GC sections
#----------------------------------------------------------------
set(DC_LDFLAGS		    "-Wl,-T,${KOS_LINKER_SCRIPT} -Wl,--gc-sections")
# Apply to all executables and shared libs
string(APPEND CMAKE_EXE_LINKER_FLAGS_INIT		" ${DC_LDFLAGS}")
string(APPEND CMAKE_SHARED_LINKER_FLAGS_INIT	" ${DC_LDFLAGS}")

# Convert paths into the same dirs variables, durr
set(DC_KOS_INCLUDE_DIRS ${DC_KOS_INCLUDE_DIRS}  CACHE PATH      "KOS include dirs")
set(DC_KOS_LIBRARY_DIRS ${DC_KOS_LIBRARY_DIRS}  CACHE PATH      "KOS library dirs")
# Default Libraries used for KOS
set(DC_KOS_DEFAULT_LIBS "kallisti;m;gcc;c"      CACHE STRING    "Default KOS libs")

# Silence RPATH
set(CMAKE_SKIP_RPATH ON)

#----------------------------------------------------------------
# Cmake helper files
#----------------------------------------------------------------
include("${CMAKE_CURRENT_LIST_DIR}/dreamcast/dc-package.cmake")
