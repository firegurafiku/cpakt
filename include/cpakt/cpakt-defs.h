#ifndef CPAKT_DEFS_H_
#define CPAKT_DEFS_H_

typedef long long cpakt_longest_int;
/** Alias for the largest available *signed* integer type.
    Both assertion arguments are implicitly casted to this type in signed
    comparison macros (`assert_int_*`). */

typedef unsigned long long cpakt_longest_uint;
/** Alias for the largest available *unsigned* integer type.
    Both assertion arguments are implicitly casted to this type in unsigned
    comparison macros (`assert_uint_*`). */

typedef void (*cpakt_test_func)(void);
/** Type for pointer to a test function.
    Here the term "test function" means one of three things:

      - test setup routine;
      - test tear-down routine;
      - the test routine itself.

    All of them are (void -> void) functions; this compatibility was chosen
    "by design" because in conventional testing it's the function name what
    determines its role. */

struct cpakt_test_record {
    char const*         name;
    cpakt_test_func     func;
};

struct cpakt_options {
    char const* setup_suffix;
    char const* teardown_suffix;
    char const* naming_scheme;
    char const* output_format;
    int         output_timestamps;
    char const* output_timestamps_format;
    int         output_reduce_paths;
    int         output_reduce_test_names;
    int         output_colors;
};

enum cpakt_func_type {
/** The role a (void -> void) function plays in a unit testing registry.
    Depending on function name, it's type may be one of the following. */

    cpakt_func_type_unknown,  /** (Type cannot be reliably detected.) */
    cpakt_func_type_test,     /** Test in a test fixture. */
    cpakt_func_type_setup,    /** Fixture constructor. */
    cpakt_func_type_teardown  /** Fixture destructor. */
};

struct cpakt_test_record_ext {
/** Another version of :struct:`cpakt_test_record` which additionally stores
    test function role as a member. Cpakt uses this structure for its internal
    test registy representation. The array of such structure objects is
    typically stored sorted, reflecting the order in which tests are queued to
    be run. */

    char const*          name;
    cpakt_test_func      func;
    enum cpakt_func_type type;
};

enum cpakt_assertion_type {
    cpakt_assertion_type_unconditional,
    cpakt_assertion_type_pointer,
    cpakt_assertion_type_integral,
    cpakt_assertion_type_string,
    cpakt_assertion_type_float,
    cpakt_assertion_type_double
};

struct cpakt_assertion_record {

    enum cpakt_assertion_type type;
    /** Denotes type of the assertion. Constants `cpakt_assertion_type_*` are
        the only valid values for this field. Once encountered an illegal value,
        formatters should stop the testing process
        using `cpakt_interrupt_testing()` function. */

    char const *a_expr;
    char const *b_expr;
    /** Point to strings, containing source code for both assertion's left-side
        and right-side expressions. For example, if the assertion statement was
        written as `assert_int_eq(10, strlen(s[0]));`, its `a_expr` would point
        to string `"10"`, `b_expr` would point to `"strlen(s[0])"`. Note that
        these string are as they're seen by the preprocessor, so they may have
        eliminated inline comments or insignificant whitespaces.

        This pointers may even be :const:`NULL` in some cases (for example, if
        assertion is unconditional). */

    char const *a_repr;
    char const *b_repr;
    /** Point to strings, containing textual representation of both assertions's
        left-side and right-side *values*. For example, if an assertion is given
        as `assert_int_le(4, sizeof(int))`, its `a_repr` will point to
        string `"4"`, `b_repr` will point to the the actual size of `int`,
        formatted as decimal number.

        Moreover, any supported data type values will be stringified according
        to C locale rules:

          - sprintf("%ld") for integral types,
          - sprintf("%p") for pointer types,
          - sprintf("%g") for float types,
          - sprintf("%s") for string types (may be truncated).

        This pointers may even be :const:`NULL` in some cases (for example, if
        assertion is unconditional). */

    char const *message;

    char const *file;
    int line;
    /** Hold the assertion location as code file name and line number.
        Filename is always presented as seen by `__FILE__` macro, so it may be
        absolute or relative to some directory. Custom formatters should
        respect `output_reduce_paths` option and not shorten paths unless
        explicitly asked to do so. */

    char const *timestamp;
    /** Unix time for the
     */
};

#endif
