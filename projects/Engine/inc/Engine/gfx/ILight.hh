// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_LIGHT_HH
#define DD25_ENGINE_GFX_I_LIGHT_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class ILight {
public:
	// Default Constructor
	ILight() = default;

	// Virtual Destructor
	virtual ~ILight() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_LIGHT_HH
//////////////////////////////////////////////////////////////////
