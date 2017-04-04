#ifndef CPAKT_IMPL_RUN_REGISTRY_H_
#define CPAKT_IMPL_RUN_REGISTRY_H_

#include <stddef.h>
#include "cpakt/cpakt-asserts.h"
#include "cpakt/cpakt-main.h"
#include "cpakt/cpakt-formatter.h"

struct cpakt_impl_test_state_record {
    cpakt_test_func key;
    void*           state;
};

struct cpakt_impl_global_state {

    struct cpakt_test_state_record *test_states;
    size_t test_states_count;
    /*  Global storage for individual test states (which can be set or
        retrieved using 'cpakt_set_state' and 'cpakt_get_state').
        These states are stored in a sorted array of
        'cpakt_test_state_record' structs, for making it fast by allowing
        binary search on them. The array is allocated only while testing
        is running, so this pointer may hold NULL value in the meantime. */
};

CPAKT_EXTERN_C
struct cpakt_impl_global_state cpakt_impl_global;

#if 0
CPAKT_EXTERN_C
int cpakt_run_registry(const struct cpakt_test_record      *registry,
                       const struct cpakt_output_formatter *formatter,
                       const struct cpakt_options          *gen_opts,
                       const void                          *spec_opts) {

    struct cpakt_test_record_ext* registry_ext = NULL;
    /*  Sorted and extended copy of original test registry. In this array
        records are stored in the order of invocation, with possible
        duplicates eliminated. */

    struct cpakt_test_state_record* registry_states = NULL;
    /*  Array of (ptr -> val) records sorted by ptr, for making state lookup
        fast by using binary search. */

    size_t reg_count = 0;
    size_t reg_ext_count = 0;
    /*  The lengths of original and extended registry. The 'reg_len_ext' should
        be close to 'reg_len', but may be slightly smaller due to possible
        duplicates elimination. */

    void *st = NULL;
    /*  Output formatter state object. Passed as first argument to each
        formatter callback. */

    struct cpakt_output_formatter default_formatter;
    struct cpakt_options          default_options;

    int result = -1;
    int num_tests_failed = 0;

    int setup_funcs_cnt = 0;

    // Sixty years on the market.
    int i;

    /*  ---  */
    
    if (registry == NULL)
        return -1;

    if (formatter == NULL) {
        cpakt_init_default_formatter(&default_formatter);
        formatter = &default_formatter;
    }
    
    if (gen_opts == NULL) {
        cpakt_init_default_options(&default_options);
        gen_opts = &default_options;
    }

    /* Lookup input 'registry' array to determine it's length. Check
       items correctness in meantime. Correct items mustn't be NULL
       and their name also mustn't be an empty string. */
    for (i = 0; ; ++i) {
        char *name = registry[i].name;
        void *func = registry[i].func;

            if (func == NULL && name == NULL)
            break;

        if (func != NULL && cpakt_impl_is_c_identifier(name))
            continue;

        cpakt_impl_set_error("Wrong registry item at index %d", i);
        return -2;
    }
    
    reg_count = i;

    registry_ext = malloc(reg_count * sizeof(*registry_ext));
    if (registry_ext == NULL)
        goto e_alloc;

    /* Iterate over 'registry' another time to copy items into writable buffer
       and determine their type at the same time. */
    for (i = 0; i < reg_count; ++i) {
        struct cpakt_test_record* rec = &registry[i];
        struct cpakt_test_record_ext* rec_ext = &registry_ext[i];

        rec_ext->name = rec->name;
        rec_ext->func = rec->func;
        rec_ext->type = cpakt_impl_detect_type(rec, gen_opts);

        if (rec_ext->type == cpakt_func_type_unknown) {
            cpakt_impl_set_error("Cannot determine entry type (%s)", rec->name);
            goto e_failure;
        }

        if (rec_ext->type == cpakt_func_type_setup)
            ++setup_funcs_cnt;
    }

    registry_states = malloc(setup_funcs_cnt * sizeof(*registry_states));
    if (registry_states == NULL)
        goto e_alloc;

    cpakt_impl_sort(registry_ext, &cpakt_registry_ext_compar ...);

    /* Check */
    if (!cpakt_impl_check_registry(registry_ext)) {
        cpakt_impl_set_error();
        result = -1;
        goto e_exit;
    }

    /* Fill. */
    j = 0;
    for (i = 0; i<reg_len_ext; ++i) {
        struct cpakt_test_record_ext rec_ext = &registry_ext[i];
        if (rec_ext->type == SETUP) {
            registry_states[j].func = rec_ext->func;
            registry_states[j].arg  = NULL;
            ++j;
        }
    }
    
    result = num_test_failed;

e_alloc:
e_exit:
    free(registry_ext);
    free(registry_states);
    
    return result;
}
#endif

#endif
