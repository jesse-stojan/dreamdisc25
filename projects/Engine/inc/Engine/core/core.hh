// Dream Disk 2025 Game Engine
// Author: Jesse Stojan
// Copyright (c) 2025 - Jesse Stojan, All Rights Reserved.
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
#define NODISCARD		[[nodiscard]]
#endif//NODISCARD

#ifndef NOEXCEPT
#define NOEXCEPT		noexcept
#endif//NOEXCEPT

#ifndef PURE
#define PURE			= 0
#endif//PURE

#ifndef VIRTUAL
#define VIRTUAL			virtual
#endif//VIRTUAL

#ifndef OVERRIDE
#define OVERRIDE		override
#endif//OVERRIDE

//================================================================

//TODO: Game Engine Stuff Here..

//////////////////////////////////////////////////////////////////
#endif//DD25_ENGINE_CORE_HH
//////////////////////////////////////////////////////////////////
