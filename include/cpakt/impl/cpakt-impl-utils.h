#ifndef CPAKT_IMPL_UTILS_H_
#define CPAKT_IMPL_UTILS_H_
#include "cpakt/impl/cpakt-impl-defs.h"

typedef int (*cpakt_impl_comparison_function)(
        const void* a, const void* b, void* arg);

CPAKT_EXTERN_C
int cpakt_impl_is_c_identifier(char const* s);

CPAKT_EXTERN_C
char const* cpakt_impl_reduce_path(char const* path);

CPAKT_EXTERN_C
void cpakt_impl_sort_r(void* array, size_t items_count, size_t item_size,
                       cpakt_impl_comparison_function comparision, void* arg);

#endif