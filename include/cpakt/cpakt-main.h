#ifndef CPAKT_H_
#define CPAKT_H_

#include "cpakt/cpakt-defs.h"
#include "cpakt/cpakt-magic.h"

// Compile-time configuration.
#define CPAKT_MAIN_SETUP_SUFFIX       "setup"
#define CPAKT_MAIN_TEARDOWN_SUFFIX    "teardown"
#define CPAKT_MAIN_NAMING_SCHEME      "mixed"
#define CPAKT_MAIN_OUTPUT_FORMAT      "cpakt"
#define CPAKT_MAIN_OUTPUT_TIMESTAMPS  1
#define CPAKT_MAIN_OUTPUT_SHORT_NAMES 1
#define CPAKT_MAIN_OUTPUT_COLORS      1

#define CPAKT_DECLARE_PROTO(name) \
    void name (void);

#define CPAKT_DECLARE_PROTOS(...) \
    CPAKT_MAGIC_EVAL(CPAKT_MAGIC_MAP(CPAKT_DECLARE_PROTO, __VA_ARGS__))

#define CPAKT_REC(test)  { #test, &test }
#define CPAKT_REC_(test) { #test, &test },
#define CPAKT_END        { (char const*)0,  (cpakt_test_function)0 }

#define CPAKT_RECS(variable, ...) \
    CPAKT_MAGIC_EVAL(CPAKT_MAGIC_MAP(CPAKT_REC_, __VA_ARGS__))

#define CPAKT_REGISTER_AND_RUN(...)                                 \
    CPAKT_DECLARE_PROTOS(__VA_ARGS__)                               \
    int main(int argc, char **argv) {                               \
        static cpakt_test_record[] = {                              \
            CPAKT_RECS(__VA_ARGS__)                                 \
            CPAKT_END                                               \
        };                                                          \
                                                                    \
        cpakt_options options;                                      \
        options.output_format      = CPAKT_MAIN_OUTPUT_FORMAT;	    \
        options.enable_timestamps  = CPAKT_MAIN_OUTPUT_TIMESTAMPS;  \
        options.enable_short_names = CPAKT_MAIN_OUTPUT_SHORT_NAMES; \
        options.enable_timestamps  = CPAKT_MAIN_OUTPUT_COLORS;      \
                                                                    \
        return cpakt_run_registry(&registry, &options, argc, argv); \
    }

int cpakt_run_registry(
        struct cpakt_test_record[],
        struct cpakt_options const*,
        int argc, char **argv);

#endif
