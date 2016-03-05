#ifndef CPAKT_DEFS_H_
#define CPAKT_DEFS_H_

typedef void (*cpakt_test_function)(void);

typedef struct {
    char const*         name;
    cpakt_test_function func;
} cpakt_test_record;

typedef struct {
    char const* output_format;
    int         enable_timestamp;
    int         enable_short_names;
    int         enable_colors;
} cpakt_options;

#endif
