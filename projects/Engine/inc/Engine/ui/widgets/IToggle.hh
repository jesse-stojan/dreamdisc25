// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_UI_WIDGET_I_TOGGLE_HH
#define DD25_ENGINE_UI_WIDGET_I_TOGGLE_HH
//////////////////////////////////////////////////////////////////

#include "../IWidget.hh"

//================================================================

class IToggle : virtual IWidget {
public:
	// Default Constructor
	IToggle();

	// Virtual Destructor
	virtual ~IToggle() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_UI_WIDGET_I_TOGGLE_HH
//////////////////////////////////////////////////////////////////
