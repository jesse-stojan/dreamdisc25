// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_UI_WIDGET_I_PANEL_HH
#define DD25_ENGINE_UI_WIDGET_I_PANEL_HH
//////////////////////////////////////////////////////////////////

#include "../IWidget.hh"

//================================================================

class IPanel : virtual IWidget {
public:
	// Default Constructor
	IPanel();

	// Virtual Destructor
	virtual ~IPanel() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_UI_WIDGET_I_PANEL_HH
//////////////////////////////////////////////////////////////////
