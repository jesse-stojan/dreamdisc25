// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_LIGHTMAP_HH
#define DD25_ENGINE_GFX_I_LIGHTMAP_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class ILightmap {
public:
	// Default Constructor
	ILightmap() = default;

	// Virtual Destructor
	virtual ~ILightmap() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_LIGHTMAP_HH
//////////////////////////////////////////////////////////////////
