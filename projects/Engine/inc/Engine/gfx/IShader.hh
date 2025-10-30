// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_SHADER_HH
#define DD25_ENGINE_GFX_I_SHADER_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class IShader {
public:
	// Default Constructor
	IShader() = default;

	// Virtual Destructor
	virtual ~IShader() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_SHADER_HH
//////////////////////////////////////////////////////////////////
