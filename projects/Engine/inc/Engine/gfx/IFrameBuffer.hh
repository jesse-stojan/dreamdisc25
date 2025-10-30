// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_FRAME_BUFFER_HH
#define DD25_ENGINE_GFX_I_FRAME_BUFFER_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class IFrameBuffer {
public:
	// Default Constructor
	IFrameBuffer() = default;

	// Virtual Destructor
	virtual ~IFrameBuffer() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_FRAME_BUFFER_HH
//////////////////////////////////////////////////////////////////
