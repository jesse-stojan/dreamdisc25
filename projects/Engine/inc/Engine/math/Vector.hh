// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_MATH_VECTOR_HH
#define DD25_ENGINE_MATH_VECTOR_HH
//////////////////////////////////////////////////////////////////

#include <type_traits>
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
#include <initializer_list>
#include <utility>

//================================================================

template <
	typename	CRTP,
	auto_number	T,
	size_t		N
>
class VecN {
public:
	using Derived		= CRTP;
	using value_type	= T;

	static constexpr size_t length = N;

	// Default Constructor
	constexpr VecN() noexcept {
		//mVal = {};
		memset(mVal, 0, sizeof(mVal));
	}

	// Copy Constructor
	constexpr VecN(const Derived& other) noexcept {
		for (size_t i = 0; i < N; ++i) {
			mVal[i] = other.mVal[i];
		}
	}

	// Move Constructor
	constexpr VecN(Derived&& other) noexcept {
		for (size_t i = 0; i < N; ++i) {
			mVal[i] = std::move(other.mVal[i]);
		}
	}

	// Initializer List Constructor
	constexpr VecN(std::initializer_list<value_type> values) noexcept {
		size_t i = 0;
		for constexpr (auto val : values) {
			mVal[i++] = val;
			if (i >= N) break;
		}
	}

	constexpr ~VecN() noexcept {
		//mVal = {};
		memset(mVal, 0, sizeof(mVal));
	}

	// Copy Assignment Operator
	inline constexpr Derived operator=(const Derived& rhs) noexcept{
		return Derived(rhs);
	}

	// Move Assignment Operator
	inline constexpr Derived operator=(Derived&& rhs) noexcept{
		return Derived(rhs);
	}

	friend inline constexpr Derived operator+(Derived& const lhs, Derived& const rhs) noexcept {
		return Derived(lhs + rhs);
	}

protected:
	friend Derived;
	value_type			mVal[N];
};

//================================================================
// vec2<T>
//================================================================

template <auto_number T>
struct vec2 : public VecN<vec2<T>, T, 2> {
public:
	using VecN::VecN;
	using value_type = T;

	// Default Constructor
	constexpr vec2() = default;

	// Fill Initialize Constructor
	constexpr vec2(value_type fillVal) noexcept {
		mVal = { fillVal, fillVal };
	}

	// Initialize Constructor
	constexpr vec2(value_type a, value_type b) noexcept {
		mVal = { a, b };
	}

	// Copy Constructor
	constexpr vec2(const vec2& other) noexcept {
		mVal = { other.mVal[0], other.mVal[1] };
	}

	// Move Constructor
	constexpr vec2(vec2&& other) noexcept {
		mVal = std::move(other.mVal);
		other.mVal = {};
	}

	// Default Destructor
	constexpr ~vec2() noexcept = default;

};

//----------------------------------------------------------------

using vec2f				= vec2<float>;
using vec2d				= vec2<double>;
using vec2ld			= vec2<long double>;
using vec2i8			= vec2<int8_t>;
using vec2i16			= vec2<int16_t>;
using vec2i32			= vec2<int32_t>;
using vec2i64			= vec2<int64_t>;
using vec2u8			= vec2<uint8_t>;
using vec2u16			= vec2<uint16_t>;
using vec2u32			= vec2<uint32_t>;
using vec2u64			= vec2<uint64_t>;

//================================================================
// vec3<T>
//================================================================

template <auto_number T>
struct vec3 : public VecN<vec3<T>, T, 3> {
public:
	using VecN::VecN;

	// Default Constructor
	vec3() = default;

	// Initialize Constructor
	constexpr vec3(T a, T b, T c) noexcept {
		mVal = { a, b, c };
	}

protected:
	union {
		T mVal[3];
	struct {
		T r, g, b;
	};
	};
};

//----------------------------------------------------------------

using vec3f				= vec3<float>;
using vec3d				= vec3<double>;
using vec3ld			= vec3<long double>;
using vec3i8			= vec3<int8_t>;
using vec3i16			= vec3<int16_t>;
using vec3i32			= vec3<int32_t>;
using vec3i64			= vec3<int64_t>;
using vec3u8			= vec3<uint8_t>;
using vec3u16			= vec3<uint16_t>;
using vec3u32			= vec3<uint32_t>;
using vec3u64			= vec3<uint64_t>;

//================================================================
// vec4<T>
//================================================================

template <auto_number T>
struct vec4 : public VecN<vec4<T>, T, 4> {
public:
	using VecN::VecN;
	using value_type = T;

	// Default Constructor
	vec4() = default;

	// Initialize Constructor
	constexpr vec4(T a, T b, T c, T d) noexcept {
		mVal = { a, b, c, d };
	}

protected:
	union {
		value_type		mVal[4];
	struct {
		value_type		a, r, g, b;
	};
	};
};

//----------------------------------------------------------------

using vec4f				= vec4<float>;
using vec4d				= vec4<double>;
using vec4ld			= vec4<long double>;
using vec4i8			= vec4<int8_t>;
using vec4i16			= vec4<int16_t>;
using vec4i32			= vec4<int32_t>;
using vec4i64			= vec4<int64_t>;
using vec4u8			= vec4<uint8_t>;
using vec4u16			= vec4<uint16_t>;
using vec4u32			= vec4<uint32_t>;
using vec4u64			= vec4<uint64_t>;

void test() {
	vec2f a1 = { 1.f, 2.f };
	vec3f b2 = { 1.f, 2.f, 3.f };
	vec4f c3 = { 1.f, 2.f, 3.f, 4.f };

	vec4f c1 = c3 + c3;
}

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_MATH_VECTOR_HH
//////////////////////////////////////////////////////////////////
