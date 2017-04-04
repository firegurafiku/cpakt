#ifndef CPAKT_IMPL_ASSERTS_H_
#define CPAKT_IMPL_ASSERTS_H_

#include "cpakt/impl/cpakt-impl-defs.h"

CPAKT_EXTERN_C
void cpakt_impl_assert_int_eq(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line);

CPAKT_EXTERN_C
void cpakt_impl_assert_int_ne(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line);

CPAKT_EXTERN_C
void cpakt_impl_assert_int_lt(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line);

CPAKT_EXTERN_C
void cpakt_impl_assert_int_le(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line);

CPAKT_EXTERN_C
void cpakt_impl_assert_int_gt(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line);

CPAKT_EXTERN_C
void cpakt_impl_assert_int_ge(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
                  char const* file, int line);

#endif
