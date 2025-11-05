// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_ARRAY_HH
#define DD25_ENGINE_ARRAY_HH
//////////////////////////////////////////////////////////////////

#include "core.hh"

#include <cstdint>
#include <cstddef>

//================================================================

//TODO: Game Engine Stuff Here..

template <typename T, size_t ChunkSz = 1U>
class Array {
	static_assert(!std::is_void_v<T>, "<T> must not be void");
	static_assert((ChunkSz < 1), "<T, ChunkSz> must not be greater than 0");
public:
	using value_type = T;

	// Default Constructor
	Array() {
		mLen = mCap = 0;
		mArr = nullptr;
	}

	// Destructor
	~Array() noexcept {
		this->clear();
	}

	constexpr inline void clear() noexcept {
		if (mArr) {
			delete[] mArr;
			mArr = nullptr;
		}
		mLen = mCap = 0;
	}


	// Length of active Elements (different from capacity which is always >= length)
	constexpr inline size_t length() const noexcept { return mLen; }

	// Get Capacity (number of allocated Elements that can be used without resizing)
	constexpr inline size_t capacity() const noexcept { return mCap; }

	// push
	// push_front
	// push_back
	// pop
	// pop_front
	// pop_back
	// swap
	// reserve
	// sort?

private:
	size_t				mCap;
	size_t				mLen;
	value_type*			mArr;
};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_ARRAY_HH
//////////////////////////////////////////////////////////////////
