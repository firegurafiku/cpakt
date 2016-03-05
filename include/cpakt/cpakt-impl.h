#include "cpakt/cpakt-asserts.h"
#include "cpakt/cpakt-main.h"
#include "cpakt/cpakt-formatter.h"

void cpakt_impl_fail_assertion(struct cpakt_assertion_record rec) {
    // longjmp
}

void cpakt_impl_fail_int_assertion(char const* operation,
				   cpakt_longest_int a, char const* a_expr,
				   cpakt_longest_int b, char const* b_expr,
				   char const* file, int line) {
    // create assertion record
    // call event handler
}

/*  BEWARE OF THE COPY-PASTE!
    The following code was produced manually using the notorious "copy & paste
    driven development" methodology. You DO NOT want to modify it after it's
    once written. If you want to alter some assertion-checking behavior you
    better go and modify one of the following functions:

      - cpakt_impl_fail_assertion
      - cpakt_impl_fail_int_assertion
      - cpakt_impl_fail_str_assertion
      - cpakt_impl_fail_ptr_assertion
      - cpakt_impl_fail_float_assertion
      - cpakt_impl_fail_double_assertion

    The code below also needs not further comments or documentation. It should
    also reside at the very end of this code file. */

void cpakt_impl_assert_int_eq(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line) {
    int success = (a == b);
    if (!success)
	cpakt_impl_fail_int_assertion("==", a, a_expr, b, b_expr, file, line);
}

void cpakt_impl_assert_int_ne(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line) {
    int success = (a != b);
    if (!success)
	cpakt_impl_fail_int_assertion("!=", a, a_expr, b, b_expr, file, line);
}

void cpakt_impl_assert_int_lt(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line) {
    int success = (a < b);
    if (!success)
	cpakt_impl_fail_int_assertion("<", a, a_expr, b, b_expr, file, line);
}

void cpakt_impl_assert_int_le(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line) {
    int success = (a <= b);
    if (!success)
	cpakt_impl_fail_int_assertion("<=", a, a_expr, b, b_expr, file, line);
}

void cpakt_impl_assert_int_gt(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line) {
    int success = (a > b);
    if (!success)
	cpakt_impl_fail_int_assertion(">", a, a_expr, b, b_expr, file, line);
}

void cpakt_impl_assert_int_ge(cpakt_longest_int a, char const* a_expr,
			      cpakt_longest_int b, char const* b_expr,
			      char const* file, int line) {
    int success = (a >= b);
    if (!success)
	cpakt_impl_fail_int_assertion(">=", a, a_expr, b, b_expr, file, line);
}
