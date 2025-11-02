// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_BACKEND_I_DIRECT3D_9_HH
#define DD25_ENGINE_GFX_BACKEND_I_DIRECT3D_9_HH
//////////////////////////////////////////////////////////////////

#include "../../IGfxBackend.hh"

//================================================================

class IGBEDirect3D9 : virtual IGfxBackend {
public:
	// Default Constructor
	IGBEDirect3D9() = default;

	// Virtual Destructor
	virtual ~IGBEDirect3D9() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_BACKEND_I_DIRECT3D_9_HH
//////////////////////////////////////////////////////////////////
