#ifndef CPAKT_MAIN_H_
#define CPAKT_MAIN_H_
#include "cpakt/cpakt-magic.h"

#define CPAKT_DECLARE_PROTO(name) void name (void);

#define CPAKT_DECLARE_PROTOS(...) \
    CPAKT_MAGIC_EVAL(CPAKT_MAGIC_MAP(CPAKT_DECLARE_PROTO, __VA_ARGS__))

#define CPAKT_REC(test)  { #test, &test }
#define CPAKT_REC_(test) { #test, &test },
#define CPAKT_END        { NULL,  NULL }

#define CPAKT_RECS(variable, ...) \
    CPAKT_MAGIC_EVAL(CPAKT_MAGIC_MAP(CPAKT_REC_, __VA_ARGS__))

#define CPAKT_REGISTER_AND_RUN(...)					\
    CPAKT_DECLARE_PROTOS(__VA_ARGS__)				        \
    int main(int argc, char **argv) {                                   \
        static cpakt_test_record[] = {                                  \
	    CPAKT_RECS(__VA_ARGS__)                                     \
	    CPAKT_END                                                   \
	};								\
	return cpakt_run_registry(registry);                            \
    }

#endif
