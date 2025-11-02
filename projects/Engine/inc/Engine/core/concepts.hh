// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_CONCEPTS_HH
#define DD25_ENGINE_CONCEPTS_HH
//////////////////////////////////////////////////////////////////

#include "core.hh"

//================================================================

#include <type_traits>
#include <typeinfo>

#if CXX_VERSION >= CXX_VERSION_20 && defined(__cpp_concepts)
#define CXX_HAS_CONCEPTS		1
#include <concepts>
#else
#define CXX_HAS_CONCEPTS		0
#endif//{ CXX_VERSION >= C++20 } else { CXX_VERSION < C++20 }

template <typename First, typename ...Next>
constexpr bool matches_type = ((std::is_same_v<First, Next> || (std::is_base_of_v<First, Next>)) || ...);

//----------------------------------------------------------------

template <typename T>
concept auto_char = matches_type<T,
	char,
	wchar_t,
	char8_t,
	char16_t,
	char32_t
>;

//----------------------------------------------------------------

template <typename T>
concept auto_integer = matches_type<T,
	char,
	short,
	int,
	long,
	long int,
	long long,
	long long int,
	unsigned char,
	unsigned short,
	unsigned int,
	unsigned long,
	unsigned long int,
	unsigned long long,
	unsigned long long int,
	signed char,
	signed short,
	signed int,
	signed long,
	signed long int,
	signed long long,
	signed long long int
>;

//----------------------------------------------------------------

template <typename T>
concept auto_uint = matches_type<T,
	unsigned char,
	unsigned short,
	unsigned int,
	unsigned long,
	unsigned long int,
	unsigned long long,
	unsigned long long int
>;

//----------------------------------------------------------------

template <typename T>
concept auto_int = matches_type<T,
	char,
	short,
	int,
	long,
	long int,
	long long,
	signed char,
	signed short,
	signed int,
	signed long,
	signed long int,
	signed long long,
	signed long long int
>;

//----------------------------------------------------------------

template <typename T>
concept auto_decimal = matches_type<T,
	float,
	double,
	long double
>;

//----------------------------------------------------------------

template <typename T>
concept auto_number = matches_type<T,
	char,
	short,
	int,
	long,
	long int,
	long long,
	unsigned char,
	unsigned short,
	unsigned int,
	unsigned long,
	unsigned long int,
	unsigned long long,
	unsigned long long int,
	signed char,
	signed short,
	signed int,
	signed long,
	signed long int,
	signed long long,
	signed long long int,
	float,
	double,
	long double
>;

//----------------------------------------------------------------
//#if CXX_HAS_CONCEPTS

// template <typename T>
// constexpr bool auto_number_t = matches_type<T,
// 	char,
// 	short,
// 	int,
// 	long,
// 	long int,
// 	long long,
// 	long long int,
// 	unsigned char,
// 	unsigned short,
// 	unsigned int,
// 	unsigned long,
// 	unsigned long int,
// 	unsigned long long,
// 	unsigned long long int,
// 	signed char,
// 	signed short,
// 	signed int,
// 	signed long,
// 	signed long int,
// 	signed long long,
// 	signed long long int,
// 	float,
// 	double,
// 	long double
// >;

template <typename T, std::enable_if_t<std::is_arithmetic_v<T>, int> = 0>
class Example {
public:
	Example() : a(0) {}
	~Example() noexcept { a = 0; }
	T get() const noexcept { return a; }
private:
	T a;
};

struct BurnerStruct {};

void test() {
	Example<int> a;
	Example<const char*> b;
	Example<BurnerStruct> c;
}

//#endif//!CXX_HAS_CONCEPTS

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_CONCEPTS_HH
//////////////////////////////////////////////////////////////////
