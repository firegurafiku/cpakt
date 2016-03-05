#ifndef CPAKT_FORMATTER_H_
#define CPAKT_FORMATTER_H_
#include "cpakt/cpakt-defs.h"

/** Output formatters API
    =====================

    All types and functions discussed in this section become available after
    including the following header file:

        #include <cpakt/cpakt-formatter.h>

    This is only necessery for writing custom output formatters; files with
    actual unit tests code shouldn't generally include this header, despite
    this API is public (not internal).

    What is output formatter?
    -------------------------
    

*/

enum cpakt_func_type {
    /** The role a (void -> void) function plays in a unit testing registry. */
    
    cpakt_func_test,     /** */
    cpakt_func_setup,
    cpakt_func_teardown
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
    cpakt_assertion_unconditional,
    cpakt_assertion_pointer,
    cpakt_assertion_integral,
    cpakt_assertion_string,
    cpakt_assertion_float,
    cpakt_assertion_double
};

struct cpakt_assertion_record {
    enum cpakt_assertion_type type;
    char const*          a_expr;
    char const*          b_expr;
    char const*          a_repr;
    char const*          b_repr;
    char const*          message;
    char const*          file;
    int                  line;
    cpakt_longest_int    timestamp;
};

struct cpakt_output_formatter_args {
    char                         const* output_file;
    int                                 is_terminal;
    struct cpakt_options         const* options;
    struct cpakt_test_record_ext const* registry;
    int                                 registry_count;
};

/** Incapsulates information, required for registering a test output
    formatter. Cpakt uses an event-driven approach to allow user to supply
    specify their own output formatting logic. Thus, this struct is just
    a set of pointer to callback functions, (almost) each taking the *state*
    as its first parameter.

    This state argument is the value returned by the `create` callback;
    it's supposed to contain any information which must be kept between the
    callbacks. Generally speaking, state should be allocate on heap
    by `create` to be freed by `destroy`. 

    The callbacks are called is the following order:

      - `create`;
      - `before_testing_start`;
      - `before_test_setup`;
      - possible `test_failed` or `test_segfault`;
      - `after_test_setup`;
      - `before_test`;
      - possible `test_failed` or `test_segfault`;
      - `after_test`;
      - `before_test_teardown`;
      - possible `test_failed` or `test_segfault`;
      - `after_test_teardown`;
      - `after_testing_end`;
      - `destroy`.

    Formatter may additionally provide a special callback named `fubar`, which
    is the last resort to more or less safely exit in case when something
    really went wrong. It may get invoked at any time.

    All these callbacks are actually optional; unused callbacks must be assigned
    to :const:`NULL`. Because there is a possibility of adding new callbacks in
    future versions of Cpakt, always use `cpakt_init_output_formatter` function
    before setting any fields of this structure.

    Additionally, test formatter may also have a name. In fact, it *must* have
    a unique name if it's supposed that user should be able to activate that
    formatter from the command line.

    Here is the complete example of registering a new formatter.

    .. code-block:: c

        #include <stdlib.h>
        #include <cpakt/cpakt-defs.h>

        static void* dummyfmt_create(void) {
            return NULL;
        }

        static void* dummyfmt_destroy(void *st) {
            (void)st;
        }

        int main() {
            struct cpakt_output_formatter formatter;
            cpakt_init_output_formatter(&formatter);
            formatter.identifier = "dummy";
            formatter.create     = &dummyfmt_create;
            formatter.destroy    = &dummyfmt_destroy;

            cpakt_register_formatter(formatter);
            return 0;
        }

     */
struct cpakt_output_formatter {

    char const* identifier;
    /** Formatter name.
        Must be a proper C language identifier, unique among other output
        formatter names. In fact, it's really needed only if the formatter
        is registered to be available to be chosen from the command line
        parameter. It's okay to set this value to :const:`NULL` if all you
        want is to pass the formatter to :func:`cpakt_run_registry`. */
    
    void* (*create)
	(struct cpakt_output_formatter_args const* args);
    /** Creates and initializes new formatter.
        This callback returns the `state` object to be passed to all other
        callbacks as their first parameters. This state is typically
        allocated from the heap and hance must be properly deallocated in
        `destroy`; however, nothing prevents `create` from returning
        a pointer to statically-allocated memory or even :const:`NULL`.

        Finally, this callback pointer may be itself safely set to
        :const:`NULL`. In this case all other callbacks get :const:`NULL`
        value as their first parameter.

        Generally speaking, this callback's duty is to allocate memory or
        do simular low-level things like that. Opening file handles,
        establishing database connection or anything relatively high-level
        should go to `before_start` callback. */
    
    void (*destroy)(void* st);
    /** Destroys and finalize. */
    
    void (*test_failed)
	(void* st, struct cpakt_assertion_record const* test);
    /** ... */
    
    void (*test_segfault)(void* st);
    /** ... */

    void (*before_start)(void* st);
    /** ... */

    void (*before_test)
	(void* st, struct cpakt_test_record_ext const* test);
    /** ... */

    void (*before_test_setup)
	(void* st, struct cpakt_test_record_ext const* setup);

    void (*before_test_teardown)
	(void* st, struct cpakt_test_record_ext const* tear);

    void (*after_end)(void* st);
    
    void (*after_test)
	(void* st, struct cpakt_test_record_ext const* test);
    
    void (*after_test_setup)
	(void* st, struct cpakt_test_record_ext const* setup);
    
    void (*after_test_teardown)
	(void* st, struct cpakt_test_record_ext const* tear);

};

#endif
