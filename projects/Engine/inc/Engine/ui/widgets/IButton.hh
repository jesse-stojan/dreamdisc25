// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_UI_WIDGET_I_BUTTON_HH
#define DD25_ENGINE_UI_WIDGET_I_BUTTON_HH
//////////////////////////////////////////////////////////////////

#include "../IWidget.hh"

//================================================================

class IButton : virtual IWidget {
public:
	// Default Constructor
	IButton();

	// Virtual Destructor
	virtual ~IButton() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_UI_WIDGET_I_BUTTON_HH
//////////////////////////////////////////////////////////////////
