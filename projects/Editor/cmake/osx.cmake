#================================================================
# [Dream Disk 25] - Editor
# ~/projects/Editor/cmake/osx.cmake
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
