// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_STRING_HH
#define DD25_ENGINE_STRING_HH
//////////////////////////////////////////////////////////////////

#include "core.hh"

#include <cstdint>
#include <cstddef>

//================================================================

//
//   CRTP = Derived Data Structure from this template,
//          (Curiously Recurring Template Pattern)
//          https://en.cppreference.com/w/cpp/language/crtp.html
// 
//      C = Character Type
// 
// BktLen = Bucket Length, for when a string needs to resize, it allocates up to at least the next BktLen.
//
template <
	typename	CRTP,
	typename	C,
	size_t		BktLen = 1U
>
class String {
public:
	using value_type = C;
	using TClass = CRTP;

	// Default Constructor
	String() = default;

	// Destructor
	~String() noexcept = default;



private:
	size_t		mCap;
	size_t		mLen;
	value_type* mStr;
};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_ARRAY_HH
//////////////////////////////////////////////////////////////////
