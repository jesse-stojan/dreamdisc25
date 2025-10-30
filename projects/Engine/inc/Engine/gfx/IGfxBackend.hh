// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_BACKEND_HH
#define DD25_ENGINE_GFX_BACKEND_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

#include "Color.hh"
#include "IBillboard.hh"
#include "IBrush.hh"
#include "ICommandQueue.hh"
#include "IFrameBuffer.hh"
#include "ILight.hh"
#include "ILightmap.hh"
#include "IMaterial.hh"
#include "IPen.hh"
#include "IShader.hh"
#include "ISprite.hh"
#include "ITexture.hh"
#include "ITileset.hh"
#include "IVertexBuffer.hh"
#include "IViewport.hh"
#include "IVisualFX.hh"

//================================================================

class IGfxBackend {
public:
	// Default Constructor
	IGfxBackend() = default;

	// Virtual Destructor
	virtual ~IGfxBackend() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_BACKEND_HH
//////////////////////////////////////////////////////////////////
