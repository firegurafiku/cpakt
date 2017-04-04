#ifndef CPAKT_ASSERTZ_H_
#define CPAKT_ASSERTZ_H_

#include "cpakt/impl/cpakt-impl-asserts.h"

#define assert_int_eq(a, b) \
    cpakt_impl_assert_int_eq((a), #a, (b), #b, __FILE__, __LINE__)

#define assert_int_ne(a, b) \
    cpakt_impl_assert_int_ne((a), #a, (b), #b, __FILE__, __LINE__)

#define assert_int_lt(a, b) \
    cpakt_impl_assert_int_lt((a), #a, (b), #b, __FILE__, __LINE__)

#define assert_int_le(a, b) \
    cpakt_impl_assert_int_le((a), #a, (b), #b, __FILE__, __LINE__)

#define assert_int_gt(a, b) \
    cpakt_impl_assert_int_gt((a), #a, (b), #b, __FILE__, __LINE__)

#define assert_int_ge(a, b) \
    cpakt_impl_assert_int_ge((a), #a, (b), #b, __FILE__, __LINE__)

#define assert_str_eq(a, b)
#define assert_str_ne(a, b)
#define assert_str_lt(a, b)
#define assert_str_le(a, b)
#define assert_str_gt(a, b)
#define assert_str_ge(a, b)

#define assert_null(ptr)
#define assert_not_null(ptr)

#define assert_true(val)
#define assert_false(val)
#define assert_that(val)

#define message(fmt, ...)
#define debug(fmt, ...)

#endif
