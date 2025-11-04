#================================================================
# [Dream Disk 25] - Engine
# ~/projects/Engine/CMakeLists.txt
#================================================================
set(TGT "DD25Engine")

project(${TGT} LANGUAGES C CXX)

set(INC ${CMAKE_CURRENT_SOURCE_DIR}/inc/Engine)
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${TGT} SHARED)

#----------------------------------------------------------------
# Public Headers
#----------------------------------------------------------------
set(ENGINE_HEADERS_PUBLIC
	# ~/inc
	${INC}/Engine.hh
	# # ~/inc/audio
	# ${INC}/audio/TODO.hh
	# ~/inc/core
	${INC}/core/Array.hh
	${INC}/core/concepts.hh
	${INC}/core/String.hh
	# # ~/inc/data
	# ${INC}/data/TODO.hh
	# ~/inc/gfx
	${INC}/gfx/Color.hh
	${INC}/gfx/IBillboard.hh
	${INC}/gfx/IBrush.hh
	${INC}/gfx/ICommandQueue.hh
	${INC}/gfx/IFrameBuffer.hh
	${INC}/gfx/IGfxBackend.hh
	${INC}/gfx/ILight.hh
	${INC}/gfx/ILightmap.hh
	${INC}/gfx/IMaterial.hh
	${INC}/gfx/IPen.hh
	${INC}/gfx/IShader.hh
	${INC}/gfx/ISprite.hh
	${INC}/gfx/ITexture.hh
	${INC}/gfx/ITileset.hh
	${INC}/gfx/IVertexBuffer.hh
	${INC}/gfx/IViewport.hh
	${INC}/gfx/IVisualFX.hh
	# # ~/inc/gfc/backend
	# ${INC}/gfx/backends/TODO.hh
	# # ~/inc/io
	# ${INC}/io/TODO.hh
	# ~/inc/math
	${INC}/math/Matrix.hh
	${INC}/math/Quaternion.hh
	${INC}/math/simd.hh
	${INC}/math/Vector.hh
	# ~/inc/physics
	${INC}/physics/Collider.hh
	${INC}/physics/Deflector.hh
	${INC}/physics/Force.hh
	${INC}/physics/Motor.hh
	${INC}/physics/Physics.hh
	${INC}/physics/Ray.hh
	# ~/inc/scene
	${INC}/scene/Camera.hh
	${INC}/scene/Curve.hh
	${INC}/scene/IComponent.hh
	${INC}/scene/ISceneObject.hh
	${INC}/scene/Mesh.hh
	${INC}/scene/Particle.hh
	${INC}/scene/Scene.hh
	# # ~/inc/system
	# ${INC}/system/TODO.hh
	# ~/inc/ui
	${INC}/ui/IWidget.hh
	# ~/inc/ui/widgets
	${INC}/ui/widgets/IButton.hh
	${INC}/ui/widgets/ICheckbox.hh
	${INC}/ui/widgets/ICursor.hh
	${INC}/ui/widgets/IDropdown.hh
	${INC}/ui/widgets/ILabel.hh
	${INC}/ui/widgets/IPanel.hh
	${INC}/ui/widgets/IProgress.hh
	${INC}/ui/widgets/IRadio.hh
	${INC}/ui/widgets/IScrollbar.hh
	${INC}/ui/widgets/ISlider.hh
	${INC}/ui/widgets/IToggle.hh
	# ~/inc/video
	${INC}/video/IVideo.hh
)

#----------------------------------------------------------------
# Source Files
#----------------------------------------------------------------
set(ENGINE_SOURCES
	${SRC}/Engine.cpp
)

#----------------------------------------------------------------
# Include target platform cmake files
#----------------------------------------------------------------
if      (DD25_TARGET_DREAMCAST)
	include("${CMAKE_CURRENT_LIST_DIR}/cmake/dreamcast.cmake")
elseif  (DD25_TARGET_WINDOWS)
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
	PUBLIC
		${INC}
)

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}/inc
	PREFIX "Header Files"
	FILES
		${ENGINE_HEADERS_PUBLIC}
)

source_group(
	TREE ${CMAKE_CURRENT_SOURCE_DIR}/src
	PREFIX "Source Files"
	FILES
		${ENGINE_SOURCES}
)

#----------------------------------------------------------------
# Target Sources
#----------------------------------------------------------------
target_sources(${TGT}
	PRIVATE
		${ENGINE_SOURCES}
	PUBLIC
		FILE_SET HEADERS
		BASE_DIRS inc
		FILES ${ENGINE_HEADERS_PUBLIC}
)

# filter: Projects
set_target_properties(${TGT} PROPERTIES FOLDER "Projects")

# filter: Third-Party
# set_target_properties(SH4ZAM	PROPERTIES FOLDER "Third-Party")
