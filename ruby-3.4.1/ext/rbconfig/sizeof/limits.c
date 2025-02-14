#include <limits.h>
#include "ruby/ruby.h"
#ifdef HAVE_STDINT_H
# include <stdint.h>
#endif
#ifdef HAVE_INTTYPES_H
# include <stdint.h>
#endif
#ifdef HAVE_FLOAT_H
# include <float.h>
#endif

/*
 * Document-const: LIMITS
 *
 * A Hash with the bounds of numeric types available to the \C compiler
 * used to build Ruby. To access this constant, first run
 * <code>require 'rbconfig/sizeof'</code>.
 *
 *    require 'rbconfig/sizeof'
 *    RUBY_PLATFORM # => "x64-mingw-ucrt"
 *    RbConfig::LIMITS.fetch_values('FIXNUM_MAX', 'LONG_MAX')
 *    # => [1073741823, 2147483647]
 *
 */

void
Init_limits(void)
{
    VALUE h = rb_hash_new();
    VALUE mRbConfig = rb_define_module("RbConfig");
    rb_define_const(mRbConfig, "LIMITS", h);

#ifdef HAVE_LONG_LONG
#ifndef ULLONG_MAX
#define ULLONG_MAX ((unsigned LONG_LONG)LLONG_MAX*2+1)
#endif
#define MAX2NUM(name) ULL2NUM(name ## _MAX)
#define MIN2NUM(name)  LL2NUM(name ## _MIN)
#else
#define MAX2NUM(name) ULONG2NUM(name ## _MAX)
#define MIN2NUM(name)  LONG2NUM(name ## _MIN)
#endif
#define DEFINE(k, v) rb_hash_aset(h, rb_usascii_str_new_lit(#k), v)

#ifdef FIXNUM_MAX
    DEFINE(FIXNUM_MAX, MAX2NUM(FIXNUM));
#endif
#ifdef FIXNUM_MIN
    DEFINE(FIXNUM_MIN, MIN2NUM(FIXNUM));
#endif
#ifdef CHAR_MAX
    DEFINE(CHAR_MAX, MAX2NUM(CHAR));
#endif
#ifdef CHAR_MIN
    DEFINE(CHAR_MIN, MIN2NUM(CHAR));
#endif
#ifdef SCHAR_MAX
    DEFINE(SCHAR_MAX, MAX2NUM(SCHAR));
#endif
#ifdef SCHAR_MIN
    DEFINE(SCHAR_MIN, MIN2NUM(SCHAR));
#endif
#ifdef UCHAR_MAX
    DEFINE(UCHAR_MAX, MAX2NUM(UCHAR));
#endif
#ifdef UCHAR_MIN
    DEFINE(UCHAR_MIN, MIN2NUM(UCHAR));
#endif
#ifdef WCHAR_MAX
    DEFINE(WCHAR_MAX, MAX2NUM(WCHAR));
#endif
#ifdef WCHAR_MIN
    DEFINE(WCHAR_MIN, MIN2NUM(WCHAR));
#endif
#ifdef SHRT_MAX
    DEFINE(SHRT_MAX, MAX2NUM(SHRT));
#endif
#ifdef SHRT_MIN
    DEFINE(SHRT_MIN, MIN2NUM(SHRT));
#endif
#ifdef USHRT_MAX
    DEFINE(USHRT_MAX, MAX2NUM(USHRT));
#endif
#ifdef USHRT_MIN
    DEFINE(USHRT_MIN, MIN2NUM(USHRT));
#endif
#ifdef INT_MAX
    DEFINE(INT_MAX, MAX2NUM(INT));
#endif
#ifdef INT_MIN
    DEFINE(INT_MIN, MIN2NUM(INT));
#endif
#ifdef UINT_MAX
    DEFINE(UINT_MAX, MAX2NUM(UINT));
#endif
#ifdef UINT_MIN
    DEFINE(UINT_MIN, MIN2NUM(UINT));
#endif
#ifdef LONG_MAX
    DEFINE(LONG_MAX, MAX2NUM(LONG));
#endif
#ifdef LONG_MIN
    DEFINE(LONG_MIN, MIN2NUM(LONG));
#endif
#ifdef ULONG_MAX
    DEFINE(ULONG_MAX, MAX2NUM(ULONG));
#endif
#ifdef ULONG_MIN
    DEFINE(ULONG_MIN, MIN2NUM(ULONG));
#endif
#ifdef LLONG_MAX
    DEFINE(LLONG_MAX, MAX2NUM(LLONG));
#endif
#ifdef LLONG_MIN
    DEFINE(LLONG_MIN, MIN2NUM(LLONG));
#endif
#ifdef ULLONG_MAX
    DEFINE(ULLONG_MAX, MAX2NUM(ULLONG));
#endif
#ifdef ULLONG_MIN
    DEFINE(ULLONG_MIN, MIN2NUM(ULLONG));
#endif
#ifdef INT8_MAX
    DEFINE(INT8_MAX, MAX2NUM(INT8));
#endif
#ifdef INT8_MIN
    DEFINE(INT8_MIN, MIN2NUM(INT8));
#endif
#ifdef UINT8_MAX
    DEFINE(UINT8_MAX, MAX2NUM(UINT8));
#endif
#ifdef UINT8_MIN
    DEFINE(UINT8_MIN, MIN2NUM(UINT8));
#endif
#ifdef INT_LEAST8_MAX
    DEFINE(INT_LEAST8_MAX, MAX2NUM(INT_LEAST8));
#endif
#ifdef INT_LEAST8_MIN
    DEFINE(INT_LEAST8_MIN, MIN2NUM(INT_LEAST8));
#endif
#ifdef UINT_LEAST8_MAX
    DEFINE(UINT_LEAST8_MAX, MAX2NUM(UINT_LEAST8));
#endif
#ifdef UINT_LEAST8_MIN
    DEFINE(UINT_LEAST8_MIN, MIN2NUM(UINT_LEAST8));
#endif
#ifdef INT_FAST8_MAX
    DEFINE(INT_FAST8_MAX, MAX2NUM(INT_FAST8));
#endif
#ifdef INT_FAST8_MIN
    DEFINE(INT_FAST8_MIN, MIN2NUM(INT_FAST8));
#endif
#ifdef UINT_FAST8_MAX
    DEFINE(UINT_FAST8_MAX, MAX2NUM(UINT_FAST8));
#endif
#ifdef UINT_FAST8_MIN
    DEFINE(UINT_FAST8_MIN, MIN2NUM(UINT_FAST8));
#endif
#ifdef INT16_MAX
    DEFINE(INT16_MAX, MAX2NUM(INT16));
#endif
#ifdef INT16_MIN
    DEFINE(INT16_MIN, MIN2NUM(INT16));
#endif
#ifdef UINT16_MAX
    DEFINE(UINT16_MAX, MAX2NUM(UINT16));
#endif
#ifdef UINT16_MIN
    DEFINE(UINT16_MIN, MIN2NUM(UINT16));
#endif
#ifdef INT_LEAST16_MAX
    DEFINE(INT_LEAST16_MAX, MAX2NUM(INT_LEAST16));
#endif
#ifdef INT_LEAST16_MIN
    DEFINE(INT_LEAST16_MIN, MIN2NUM(INT_LEAST16));
#endif
#ifdef UINT_LEAST16_MAX
    DEFINE(UINT_LEAST16_MAX, MAX2NUM(UINT_LEAST16));
#endif
#ifdef UINT_LEAST16_MIN
    DEFINE(UINT_LEAST16_MIN, MIN2NUM(UINT_LEAST16));
#endif
#ifdef INT_FAST16_MAX
    DEFINE(INT_FAST16_MAX, MAX2NUM(INT_FAST16));
#endif
#ifdef INT_FAST16_MIN
    DEFINE(INT_FAST16_MIN, MIN2NUM(INT_FAST16));
#endif
#ifdef UINT_FAST16_MAX
    DEFINE(UINT_FAST16_MAX, MAX2NUM(UINT_FAST16));
#endif
#ifdef UINT_FAST16_MIN
    DEFINE(UINT_FAST16_MIN, MIN2NUM(UINT_FAST16));
#endif
#ifdef INT32_MAX
    DEFINE(INT32_MAX, MAX2NUM(INT32));
#endif
#ifdef INT32_MIN
    DEFINE(INT32_MIN, MIN2NUM(INT32));
#endif
#ifdef UINT32_MAX
    DEFINE(UINT32_MAX, MAX2NUM(UINT32));
#endif
#ifdef UINT32_MIN
    DEFINE(UINT32_MIN, MIN2NUM(UINT32));
#endif
#ifdef INT_LEAST32_MAX
    DEFINE(INT_LEAST32_MAX, MAX2NUM(INT_LEAST32));
#endif
#ifdef INT_LEAST32_MIN
    DEFINE(INT_LEAST32_MIN, MIN2NUM(INT_LEAST32));
#endif
#ifdef UINT_LEAST32_MAX
    DEFINE(UINT_LEAST32_MAX, MAX2NUM(UINT_LEAST32));
#endif
#ifdef UINT_LEAST32_MIN
    DEFINE(UINT_LEAST32_MIN, MIN2NUM(UINT_LEAST32));
#endif
#ifdef INT_FAST32_MAX
    DEFINE(INT_FAST32_MAX, MAX2NUM(INT_FAST32));
#endif
#ifdef INT_FAST32_MIN
    DEFINE(INT_FAST32_MIN, MIN2NUM(INT_FAST32));
#endif
#ifdef UINT_FAST32_MAX
    DEFINE(UINT_FAST32_MAX, MAX2NUM(UINT_FAST32));
#endif
#ifdef UINT_FAST32_MIN
    DEFINE(UINT_FAST32_MIN, MIN2NUM(UINT_FAST32));
#endif
#ifdef INT64_MAX
    DEFINE(INT64_MAX, MAX2NUM(INT64));
#endif
#ifdef INT64_MIN
    DEFINE(INT64_MIN, MIN2NUM(INT64));
#endif
#ifdef UINT64_MAX
    DEFINE(UINT64_MAX, MAX2NUM(UINT64));
#endif
#ifdef UINT64_MIN
    DEFINE(UINT64_MIN, MIN2NUM(UINT64));
#endif
#ifdef INT_LEAST64_MAX
    DEFINE(INT_LEAST64_MAX, MAX2NUM(INT_LEAST64));
#endif
#ifdef INT_LEAST64_MIN
    DEFINE(INT_LEAST64_MIN, MIN2NUM(INT_LEAST64));
#endif
#ifdef UINT_LEAST64_MAX
    DEFINE(UINT_LEAST64_MAX, MAX2NUM(UINT_LEAST64));
#endif
#ifdef UINT_LEAST64_MIN
    DEFINE(UINT_LEAST64_MIN, MIN2NUM(UINT_LEAST64));
#endif
#ifdef INT_FAST64_MAX
    DEFINE(INT_FAST64_MAX, MAX2NUM(INT_FAST64));
#endif
#ifdef INT_FAST64_MIN
    DEFINE(INT_FAST64_MIN, MIN2NUM(INT_FAST64));
#endif
#ifdef UINT_FAST64_MAX
    DEFINE(UINT_FAST64_MAX, MAX2NUM(UINT_FAST64));
#endif
#ifdef UINT_FAST64_MIN
    DEFINE(UINT_FAST64_MIN, MIN2NUM(UINT_FAST64));
#endif
#ifdef INT128_MAX
    DEFINE(INT128_MAX, MAX2NUM(INT128));
#endif
#ifdef INT128_MIN
    DEFINE(INT128_MIN, MIN2NUM(INT128));
#endif
#ifdef UINT128_MAX
    DEFINE(UINT128_MAX, MAX2NUM(UINT128));
#endif
#ifdef UINT128_MIN
    DEFINE(UINT128_MIN, MIN2NUM(UINT128));
#endif
#ifdef INTMAX_MAX
    DEFINE(INTMAX_MAX, MAX2NUM(INTMAX));
#endif
#ifdef INTMAX_MIN
    DEFINE(INTMAX_MIN, MIN2NUM(INTMAX));
#endif
#ifdef UINTMAX_MAX
    DEFINE(UINTMAX_MAX, MAX2NUM(UINTMAX));
#endif
#ifdef UINTMAX_MIN
    DEFINE(UINTMAX_MIN, MIN2NUM(UINTMAX));
#endif
#ifdef INTPTR_MAX
    DEFINE(INTPTR_MAX, MAX2NUM(INTPTR));
#endif
#ifdef INTPTR_MIN
    DEFINE(INTPTR_MIN, MIN2NUM(INTPTR));
#endif
#ifdef UINTPTR_MAX
    DEFINE(UINTPTR_MAX, MAX2NUM(UINTPTR));
#endif
#ifdef UINTPTR_MIN
    DEFINE(UINTPTR_MIN, MIN2NUM(UINTPTR));
#endif
#ifdef SSZIE_MAX
    DEFINE(SSZIE_MAX, MAX2NUM(SSZIE));
#endif
#ifdef SSZIE_MIN
    DEFINE(SSZIE_MIN, MIN2NUM(SSZIE));
#endif
#ifdef SIZE_MAX
    DEFINE(SIZE_MAX, MAX2NUM(SIZE));
#endif
#ifdef SIZE_MIN
    DEFINE(SIZE_MIN, MIN2NUM(SIZE));
#endif
#ifdef PTRDIFF_MAX
    DEFINE(PTRDIFF_MAX, MAX2NUM(PTRDIFF));
#endif
#ifdef PTRDIFF_MIN
    DEFINE(PTRDIFF_MIN, MIN2NUM(PTRDIFF));
#endif

#ifdef FLT_RADIX
    DEFINE(FLT_RADIX, LONG2NUM(FLT_RADIX));
#endif
#ifdef FLT_ROUNDS
    DEFINE(FLT_ROUNDS, LONG2NUM(FLT_ROUNDS));
#endif
#ifdef FLT_EVAL_METHOD
    DEFINE(FLT_EVAL_METHOD, LONG2NUM(FLT_EVAL_METHOD));
#endif
#ifdef FLT_MANT_DIG
    DEFINE(FLT_MANT_DIG, LONG2NUM(FLT_MANT_DIG));
#endif
#ifdef DBL_MANT_DIG
    DEFINE(DBL_MANT_DIG, LONG2NUM(DBL_MANT_DIG));
#endif
#ifdef LDBL_MANT_DIG
    DEFINE(LDBL_MANT_DIG, LONG2NUM(LDBL_MANT_DIG));
#endif
#ifdef FLT_DIG
    DEFINE(FLT_DIG, LONG2NUM(FLT_DIG));
#endif
#ifdef DBL_DIG
    DEFINE(DBL_DIG, LONG2NUM(DBL_DIG));
#endif
#ifdef LDBL_DIG
    DEFINE(LDBL_DIG, LONG2NUM(LDBL_DIG));
#endif
#ifdef FLT_MIN_EXP
    DEFINE(FLT_MIN_EXP, LONG2NUM(FLT_MIN_EXP));
#endif
#ifdef DBL_MIN_EXP
    DEFINE(DBL_MIN_EXP, LONG2NUM(DBL_MIN_EXP));
#endif
#ifdef LDBL_MIN_EXP
    DEFINE(LDBL_MIN_EXP, LONG2NUM(LDBL_MIN_EXP));
#endif
#ifdef FLT_MIN_10_EXP
    DEFINE(FLT_MIN_10_EXP, LONG2NUM(FLT_MIN_10_EXP));
#endif
#ifdef DBL_MIN_10_EXP
    DEFINE(DBL_MIN_10_EXP, LONG2NUM(DBL_MIN_10_EXP));
#endif
#ifdef LDBL_MIN_10_EXP
    DEFINE(LDBL_MIN_10_EXP, LONG2NUM(LDBL_MIN_10_EXP));
#endif
#ifdef FLT_MAX_EXP
    DEFINE(FLT_MAX_EXP, LONG2NUM(FLT_MAX_EXP));
#endif
#ifdef DBL_MAX_EXP
    DEFINE(DBL_MAX_EXP, LONG2NUM(DBL_MAX_EXP));
#endif
#ifdef LDBL_MAX_EXP
    DEFINE(LDBL_MAX_EXP, LONG2NUM(LDBL_MAX_EXP));
#endif
#ifdef FLT_MAX_10_EXP
    DEFINE(FLT_MAX_10_EXP, LONG2NUM(FLT_MAX_10_EXP));
#endif
#ifdef DBL_MAX_10_EXP
    DEFINE(DBL_MAX_10_EXP, LONG2NUM(DBL_MAX_10_EXP));
#endif
#ifdef LDBL_MAX_10_EXP
    DEFINE(LDBL_MAX_10_EXP, LONG2NUM(LDBL_MAX_10_EXP));
#endif
#ifdef FLT_DECIMAL_DIG
    DEFINE(FLT_DECIMAL_DIG, LONG2NUM(FLT_DECIMAL_DIG));
#endif
#ifdef DBL_DECIMAL_DIG
    DEFINE(DBL_DECIMAL_DIG, LONG2NUM(DBL_DECIMAL_DIG));
#endif
#ifdef LDBL_DECIMAL_DIG
    DEFINE(LDBL_DECIMAL_DIG, LONG2NUM(LDBL_DECIMAL_DIG));
#endif
#ifdef DECIMAL_DIG
    DEFINE(DECIMAL_DIG, LONG2NUM(DECIMAL_DIG));
#endif
#ifdef FLT_HAS_SUBNORM
    DEFINE(FLT_HAS_SUBNORM, LONG2NUM(FLT_HAS_SUBNORM));
#endif
#ifdef DBL_HAS_SUBNORM
    DEFINE(DBL_HAS_SUBNORM, LONG2NUM(DBL_HAS_SUBNORM));
#endif
#ifdef LDBL_HAS_SUBNORM
    DEFINE(LDBL_HAS_SUBNORM, LONG2NUM(LDBL_HAS_SUBNORM));
#endif

#ifdef FLT_MAX
    DEFINE(FLT_MAX, DBL2NUM(FLT_MAX));
#endif
#ifdef DBL_MAX
    DEFINE(DBL_MAX, DBL2NUM(DBL_MAX));
#endif
#ifdef FLT_EPSILON
    DEFINE(FLT_EPSILON, DBL2NUM(FLT_EPSILON));
#endif
#ifdef DBL_EPSILON
    DEFINE(DBL_EPSILON, DBL2NUM(DBL_EPSILON));
#endif
#ifdef FLT_MIN
    DEFINE(FLT_MIN, DBL2NUM(FLT_MIN));
#endif
#ifdef DBL_MIN
    DEFINE(DBL_MIN, DBL2NUM(DBL_MIN));
#endif
#ifdef FLT_TRUE_MIN
    DEFINE(FLT_TRUE_MIN, DBL2NUM(FLT_TRUE_MIN));
#endif
#ifdef DBL_TRUE_MIN
    DEFINE(DBL_TRUE_MIN, DBL2NUM(DBL_TRUE_MIN));
#endif

#undef DEFINE
#undef MIN2NUM
#undef MAX2NUM
    OBJ_FREEZE(h);
}
