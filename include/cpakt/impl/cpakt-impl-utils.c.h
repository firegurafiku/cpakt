#include <ctype.h>
#include "cpakt/impl/cpakt-impl-defs.h"
#include "cpakt/impl/cpakt-impl-utils.h"

CPAKT_EXTERN_C
int cpakt_impl_is_c_identifier(char const* s) {
    char const* i = s;

    /* Strictly speaking, NULL is incorrect input. But getting SEGFAULT for such
       a stupid reason would be a shame. */
    if (s == NULL)
        return 0;

    /* BTW, note that isalpha() is locale-dependent. */
    if (!isalpha(*i))
        return 0;

    i++;
    while (isalnum(*i))
        i++;

    return (*i == '\0');
}

CPAKT_EXTERN_C
char const* cpakt_impl_reduce_path(char const *path) {
    char const *last;
    char const *cur;

    if (path == NULL)
        return NULL;

    last = path;
    cur  = path;
    for ( ; *cur != '\0'; ++cur) {
    if (*cur == '/' || *cur == '\\')
        last = cur + 1;
    }

    return last;
}

CPAKT_EXTERN_C
void cpakt_impl_sort_r(void* array, size_t items_count, size_t item_size,
                       cpakt_impl_comparison_function comparision, void* arg) {

    // TODO: Implement our own sorting function.
    qsort_r(array, items_count, item_size, comparision, arg);
}
