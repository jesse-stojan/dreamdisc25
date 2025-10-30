// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_VERTEX_BUFFER_HH
#define DD25_ENGINE_GFX_I_VERTEX_BUFFER_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class IVertexBuffer {
public:
	// Default Constructor
	IVertexBuffer() = default;

	// Virtual Destructor
	virtual ~IVertexBuffer() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_VERTEX_BUFFER_HH
//////////////////////////////////////////////////////////////////
