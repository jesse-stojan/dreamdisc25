// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 Jesse Stojan.
#pragma once

//////////////////////////////////////////////////////////////////
#ifndef DD25_ENGINE_CORE_HH
#define DD25_ENGINE_CORE_HH
//////////////////////////////////////////////////////////////////

//================================================================
// Platforms
//================================================================
#if defined(__DREAMCAST__)
//TODO: Dreamcast

#elif defined(_MSC_VER)
//TODO: Windows

#elif defined(__APPLE__)
//TODO: macOS

#elif defined(__freebsd__)
//TODO: FreeBSD

#elif defined(__linux__)
//TODO: Linux

#endif//Windows, macOS, BSD, Linux

//================================================================
// Compilers
//================================================================
#if defined(_MSC_VER) && !defined(__clang__)
//TODO: MSVC
#if defined(DD25_ENGINE_EXPORT)
#define DD25_API				__declspec(dllexport)
#else
#define DD25_API				__declspec(dllimport)
#endif//DD25_ENGINE_EXPORT

#elif defined(__clang__)
//TODO: Clang
#ifdef DD25_ENGINE_EXPORT
#define DD25_API				__attribute__((visibility("default")))
#else
#define DD25_API				// blank
#endif

#elif defined(__GNUC__)
//TODO: GCC
#ifdef DD25_ENGINE_EXPORT
#define DD25_API				__attribute__((visibility("default")))
#else
#define DD25_API				// blank
#endif

#endif// MSVC, Clang, GCC

//================================================================
// C++ Version
//================================================================

#ifndef CXX_VERSION_26
#define CXX_VERSION_26	202400L
#endif//CXX_VERSION_26

#ifndef CXX_VERSION_23
#define CXX_VERSION_23	202302L
#endif//CXX_VERSION_23

#ifndef CXX_VERSION_20
#define CXX_VERSION_20	202002L
#endif//CXX_VERSION_20

#ifndef CXX_VERSION_17
#define CXX_VERSION_17	201703L
#endif//CXX_VERSION_17

#ifndef CXX_VERSION_14
#define CXX_VERSION_14	201402L
#endif//CXX_VERSION_14

#ifndef CXX_VERSION_11
#define CXX_VERSION_11	201103L
#endif//CXX_VERSION_11

#ifndef CXX_VERSION_03
#define CXX_VERSION_03	199711L
#endif//CXX_VERSION_03

//----------------------------------------------------------------

#if defined(__cplusplus)
#if		__cplusplus >= CXX_VERSION_26
#define CXX_VERSION		CXX_VERSION_26
#elif	__cplusplus >= CXX_VERSION_23
#define CXX_VERSION		CXX_VERSION_23
#elif	__cplusplus >= CXX_VERSION_20
#define CXX_VERSION		CXX_VERSION_20
#elif	__cplusplus >= CXX_VERSION_17
#define CXX_VERSION		CXX_VERSION_17
#elif	__cplusplus >= CXX_VERSION_14
#define CXX_VERSION		CXX_VERSION_14
#elif	__cplusplus >= CXX_VERSION_11
#define CXX_VERSION		CXX_VERSION_11
#else
#define CXX_VERSION		CXX_VERSION_03
#endif//CXX_VERSION
#endif//__cplusplus

//================================================================

#ifndef EXTERN_C_BEGIN
#define EXTERN_C_BEING	extern "C" {
#endif//EXTERN_C_BEGIN

#ifndef EXTERN_C_END
#define EXTERN_C_END	}
#endif//EXTERN_C_END

#ifndef EXTERN_C
#define EXTERN_C		extern "C"
#endif//EXTERN_C

//================================================================

#ifndef NODISCARD
//NOTE:
// This attribute was introduced in C++17
// C++20 adds an optional `[[nodiscard("reason")]]
#define NODISCARD		[[nodiscard]]
#endif//NODISCARD

#ifndef NORETURN
//NOTE: Introduced in C++11
#define NORETURN		[[noreturn]]
#endif//NORETURN

#ifndef PURE
#define PURE			= 0
#endif//PURE

//================================================================

//TODO: Game Engine Stuff Here..

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_CORE_HH
//////////////////////////////////////////////////////////////////
