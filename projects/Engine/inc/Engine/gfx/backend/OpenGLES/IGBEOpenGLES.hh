// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_BACKEND_I_OPEN_GL_ES_HH
#define DD25_ENGINE_GFX_BACKEND_I_OPEN_GL_ES_HH
//////////////////////////////////////////////////////////////////

#include "../../IGfxBackend.hh"

//================================================================

class IGBEOpenGLES : virtual IGfxBackend {
public:
	// Default Constructor
	IGBEOpenGLES() = default;

	// Virtual Destructor
	virtual ~IGBEOpenGLES() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_BACKEND_I_OPEN_GL_ES_HH
//////////////////////////////////////////////////////////////////
