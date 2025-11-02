// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_BACKEND_I_POWER_VR_HH
#define DD25_ENGINE_GFX_BACKEND_I_POWER_VR_HH
//////////////////////////////////////////////////////////////////

#include "../../IGfxBackend.hh"

//================================================================

class IGBEPowerVR : virtual IGfxBackend {
public:
	// Default Constructor
	IGBEPowerVR() = default;

	// Virtual Destructor
	virtual ~IGBEPowerVR() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_BACKEND_I_POWER_VR_HH
//////////////////////////////////////////////////////////////////
