// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_VIEWPORT_HH
#define DD25_ENGINE_GFX_I_VIEWPORT_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class IViewport {
public:
	// Default Constructor
	IViewport() = default;

	// Virtual Destructor
	virtual ~IViewport() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_VIEWPORT_HH
//////////////////////////////////////////////////////////////////
