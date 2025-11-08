#================================================================
# [Dream Disk 25] - Engine
# ~/projects/Engine/cmake/osx.cmake
#================================================================

#----------------------------------------------------------------
# Link Frameworks:
#----------------------------------------------------------------
target_link_libraries(${TGT} PRIVATE
	"-framework OpenGL"
	"-framework Cocoa"
	"-framework IOKit"
	"-framework CoreVideo"
)
