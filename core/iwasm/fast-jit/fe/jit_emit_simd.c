/*
 * Copyright (C) 2019 Intel Corporation. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
 */

#include "jit_emit_simd.h"
#include "../jit_frontend.h"

bool
jit_compile_op_v128_const(JitCompContext *cc, const uint8 *bytes)
{
    JitReg value = NEW_CONST(V128, bytes);
    PUSH_V128(value);
    return true;
fail:
    return false;
}

#define DEF_V128_BINARY_OP(op, err)          \
    do {                                     \
        JitReg res, left, right;             \
        POP_V128(right);                     \
        POP_V128(left);                      \
        if (!(res = op)) {                   \
            if (err)                         \
                jit_set_last_error(cc, err); \
            goto fail;                       \
        }                                    \
        PUSH_V128(res);                      \
    } while (0)


bool
compile_i32x4_add(JitCompContext *cc, JitReg lhs, JitReg rhs)
{
    JitReg res;
    // TODO: does not process constants

    res = jit_cc_new_reg_V128(cc);
    GEN_INSN(VECADD, res, lhs, rhs, JIT_SIMD_KIND_I32X4);

    return res;
}

bool
jit_compile_op_i32x4_arith(JitCompContext *cc, V128Arithmetic arith_op)
{
    switch (arith_op)
    {
        case V128_ADD:
            DEF_V128_BINARY_OP(compile_i32x4_add(cc, left, right),
                              "compile i32x4 add fail.");
            break;
        default:
            bh_assert(0);
            return false;
    }
    return true;
fail:
    return false;
}