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
    determines its role.
*/

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


#endif
