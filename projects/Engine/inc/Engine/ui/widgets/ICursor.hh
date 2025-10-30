// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_UI_WIDGET_I_CURSOR_HH
#define DD25_ENGINE_UI_WIDGET_I_CURSOR_HH
//////////////////////////////////////////////////////////////////

#include "../IWidget.hh"

//================================================================

class ICursor : virtual IWidget {
public:
	// Default Constructor
	ICursor();

	// Virtual Destructor
	virtual ~ICursor() noexcept;

private:

};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_UI_WIDGET_I_CURSOR_HH
//////////////////////////////////////////////////////////////////
