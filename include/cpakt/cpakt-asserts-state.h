#ifnder CPAKT_ASSERTS_STATE_H_
#define CPAKT_ASSERTS_STATE_H_

#include "cpakt/cpakt-defs.h"
#include "cpakt/impl/cpakt-impl-defs.h"

CPAKT_EXTERN_C
void* cpakt_get_state(cpakt_test_func setup);
/** Gets explicit state object which was set by the `setup` routine. */

CPAKT_EXTERN_C
void cpakt_set_state(cpakt_test_func setup, void *val);

#endif
