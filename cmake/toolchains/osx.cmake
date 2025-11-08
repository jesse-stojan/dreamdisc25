# osx.cmake

#----------------------------------------------------------------
# Set System Name
#----------------------------------------------------------------
set(CMAKE_SYSTEM_NAME Darwin)

#----------------------------------------------------------------
# Language standards
#----------------------------------------------------------------
# The unsafe language, C
set(CMAKE_C_STANDARD                    17)
set(CMAKE_C_STANDARD_REQUIRED           ON)
set(CMAKE_C_EXTENSIONS                  OFF)

# C++
set(CMAKE_CXX_STANDARD                  20)
set(CMAKE_CXX_STANDARD_REQUIRED         ON)
set(CMAKE_CXX_EXTENSIONS                OFF)

# # Objective-C
# enable_language(OBJC)
# set(CMAKE_OBJC_STANDARD                 17)
# set(CMAKE_OBJC_STANDARD_REQUIRED        ON)
# set(CMAKE_OBJC_EXTENSIONS               OFF)

# # Objective-C++
# enable_language(OBJCXX)
# set(CMAKE_OBJCXX_STANDARD               20)
# set(CMAKE_OBJCXX_STANDARD_REQUIRED      ON)
# set(CMAKE_OBJCXX_EXTENSIONS             OFF)

##----------------------------------------------------------------
## Compilers
##----------------------------------------------------------------
#if (NOT CMAKE_C_COMPILER)
#	set(CMAKE_C_COMPILER clang)
#endif()
#if (NOT CMAKE_CXX_COMPILER)
#	set(CMAKE_CXX_COMPILER clang++)
#endif()

#----------------------------------------------------------------
# Preprocessor Definitions
#----------------------------------------------------------------
add_compile_definitions(
	DD25_MACOS=1
	DD25_PLATFORM_DESKTOP=1
)

#----------------------------------------------------------------
# Apple Clang: Silence OpenGL Deprecation Warnings
#----------------------------------------------------------------
if (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang" OR CMAKE_C_COMPILER_ID STREQUAL "AppleClang")
	# Silence OpenGL Framework deprecated
	add_compile_definitions(
		GL_SILENCE_DEPRECATION=1
	)
	# Silence framework deprecation warnings
	add_compile_options(
		"-Wno-deprecated-declarations"          # General "Deprecated Symbols"
		"-Wno-deprecated"                       # Older Clang General "Deprecated Symbols"
		"-Wno-deprecated-declarations"          # andddddddd... redundancy
		"-Wno-deprecated-gl-apis"               # Apple - OpenGL API warnings
	)
endif()
