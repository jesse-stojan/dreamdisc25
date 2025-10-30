// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_BACKEND_HH
#define DD25_ENGINE_GFX_BACKEND_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

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
