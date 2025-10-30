// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_TEXTURE_HH
#define DD25_ENGINE_GFX_I_TEXTURE_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class ITexture {
public:
	// Default Constructor
	ITexture() = default;

	// Virtual Destructor
	virtual ~ITexture() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_TEXTURE_HH
//////////////////////////////////////////////////////////////////
