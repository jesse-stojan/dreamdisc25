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

#if CXX_VERSION >= CXX_VERSION_20
#include <concepts>
#endif//C++20 or higher

template <typename First, typename ...Next>
constexpr bool matches_type = ((std::is_same_v<First, Next> || std::is_base_of_v<First, Next>) || ...);

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
	signed int,
	signed long,
	signed long int,
	signed long long,
	signed long long int
>;

//----------------------------------------------------------------

template <typename T>
concept auto_decimal = matches_type <T,
	float,
	double,
	long double
>;

//----------------------------------------------------------------

template <typename T>
concept auto_number = matches_type <T,
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

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_CONCEPTS_HH
//////////////////////////////////////////////////////////////////
