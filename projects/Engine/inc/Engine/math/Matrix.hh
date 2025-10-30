// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_MATH_MATRIX_HH
#define DD25_ENGINE_MATH_MATRIX_HH
//////////////////////////////////////////////////////////////////

#include <cstdint>
#include <cstddef>

#include "simd.hh"

//================================================================

template <size_t Cols, size_t Rows>
class MatrixN {
public:
	using value_type = float;



private:
	union {
		value_type		a[Cols * Rows];
		value_type		m[Cols][Rows];
	}	mVal;
};

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_MATH_MATRIX_HH
//////////////////////////////////////////////////////////////////
