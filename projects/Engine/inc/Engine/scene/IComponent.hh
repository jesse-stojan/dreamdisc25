// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_SCENE_I_COMPONENT_HH
#define DD25_ENGINE_SCENE_I_COMPONENT_HH
//////////////////////////////////////////////////////////////////

#include "Mesh.hh"

//================================================================

class IComponent {
public:
	// Default Constructor
	IComponent() = default;

	// Virtual Destructor
	virtual ~IComponent() noexcept = default;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_SCENE_I_COMPONENT_HH
//////////////////////////////////////////////////////////////////
