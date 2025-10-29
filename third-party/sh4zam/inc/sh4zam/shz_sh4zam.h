/*! \file
 *  \brief   Aggregate include file for C API.
 *
 *  This file is intended to be a way to include everything
 *  the SH4ZAM library has to offer to the C language within
 *  a single header file.
 *
 *  \author    Falco Girgis
 *  \copyright MIT License
 */

#ifndef SHZ_SH4ZAM_H
#define SHZ_SH4ZAM_H

#ifdef __cplusplus
#ifndef EXTERN_C_BEGIN
#define EXTERN_C_BEGIN	extern "C" {
#endif//EXTERN_C_BEING
#ifndef EXTERN_C_END
#define EXTERN_C_END	}
#endif//EXTERN_C_END
#else
#ifndef EXTERN_C_BEGIN
#define EXTERN_C_BEGIN
#endif//EXTERN_C_BEING
#ifndef EXTERN_C_END
#define EXTERN_C_END
#endif//EXTERN_C_END
#endif

EXTERN_C_BEGIN

#include "shz_cdefs.h"
#include "shz_fpscr.h"
#include "shz_mem.h"
#include "shz_scalar.h"
#include "shz_trig.h"
#include "shz_vector.h"
#include "shz_quat.h"
#include "shz_matrix.h"
#include "shz_xmtrx.h"
#include "shz_circle.h"

EXTERN_C_END

#endif