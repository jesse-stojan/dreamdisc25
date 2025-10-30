// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_UI_WIDGET_I_SCROLLBAR_HH
#define DD25_ENGINE_UI_WIDGET_I_SCROLLBAR_HH
//////////////////////////////////////////////////////////////////

#include "../IWidget.hh"

//================================================================

class IScrollbar : virtual IWidget {
public:
	// Default Constructor
	IScrollbar();

	// Virtual Destructor
	virtual ~IScrollbar() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_UI_WIDGET_I_SCROLLBAR_HH
//////////////////////////////////////////////////////////////////
