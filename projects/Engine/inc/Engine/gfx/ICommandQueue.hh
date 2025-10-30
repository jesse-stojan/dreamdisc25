// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_GFX_I_COMMAND_QUEUE_HH
#define DD25_ENGINE_GFX_I_COMMAND_QUEUE_HH
//////////////////////////////////////////////////////////////////

#include "../core/core.hh"

//================================================================

class ICommandQueue {
public:
	// Default Constructor
	ICommandQueue() = default;

	// Virtual Destructor
	virtual ~ICommandQueue() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_GFX_I_COMMAND_QUEUE_HH
//////////////////////////////////////////////////////////////////
