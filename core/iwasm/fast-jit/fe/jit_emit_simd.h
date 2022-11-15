
/*
 * Copyright (C) 2022 Intel Corporation. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#ifndef _JIT_EMIT_SIMD_H_
#define _JIT_EMIT_SIMD_H_

#include "../jit_compiler.h"
#include "../jit_frontend.h"

#ifdef __cplusplus
extern "C" {
#endif

bool
jit_compile_op_v128_const(JitCompContext *cc, const uint8 *bytes);


bool
jit_compile_op_i32x4_arith(JitCompContext *cc, V128Arithmetic artih_op);

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* end of _JIT_EMIT_CONST_H_ */
