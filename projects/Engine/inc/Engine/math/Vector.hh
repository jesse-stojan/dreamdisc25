// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_MATH_VECTOR_HH
#define DD25_ENGINE_MATH_VECTOR_HH
//////////////////////////////////////////////////////////////////

#include "../core/concepts.hh"
#include "simd.hh"

#if defined(__DREAMCAST__)
// Dreamcast
#include <sh4zam/shz_sh4zam.hpp>
#else
// Windows, macOS, FreeBSD, Linux
#include <cstdint>
#include <cfloat>

// SIMD
#if defined(_MSC_VER)
#include <immintrin.h>
#else
#include <intrin.h>
#endif
#endif// Dreamcast, (Windows, macOS, FreeBSD, Linux)

//================================================================

template <auto_number T, size_t N>
class VectorN {
public:
	using value_type = T;

	// Default Constructor
	VectorN() {
		mVal = {};
	}

	~VectorN() noexcept {
		mVal = {};
	}

private:
	value_type			mVal[N];
};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_MATH_VECTOR_HH
//////////////////////////////////////////////////////////////////
