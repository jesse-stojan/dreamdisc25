// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_SCENE_I_ENTITY_COMPONENT_HH
#define DD25_ENGINE_SCENE_I_ENTITY_COMPONENT_HH
//////////////////////////////////////////////////////////////////

#include "Mesh.hh"

//================================================================

class IEntityComponent {
public:
	// Default Constructor
	IEntityComponent() = default;

	// Virtual Destructor
	virtual ~IEntityComponent() noexcept = default;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_SCENE_I_ENTITY_COMPONENT_HH
//////////////////////////////////////////////////////////////////
