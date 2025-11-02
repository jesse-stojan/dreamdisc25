// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_BACKEND_I_OPEN_GL_HH
#define DD25_ENGINE_GFX_BACKEND_I_OPEN_GL_HH
//////////////////////////////////////////////////////////////////

#include "../../IGfxBackend.hh"

//================================================================

class IGBEOpenGL : virtual IGfxBackend {
public:
	// Default Constructor
	IGBEOpenGL() = default;

	// Virtual Destructor
	virtual ~IGBEOpenGL() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_BACKEND_I_OPEN_GL_HH
//////////////////////////////////////////////////////////////////
