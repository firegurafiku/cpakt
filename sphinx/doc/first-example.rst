First unit test example
=======================

The recommended way for using Cpakt is to have separate files for test
functions, and one file for test registry.

 .. code-block:: c
    :caption: first-test/test_main.c

    #include <cpakt/cpakt-main.h>
    CPAKT_RUN_REGISTRY(
        test_strncpy_setup,
        test_strncpy_teardown,
        test_strncpy_1,
        test_strncpy_2
    )

 .. code-block:: c
    :caption: first-test/test_strncpy.c

    #include <stdlib.h>
    #include <cpakt/cpakt-assertz.h>

    void test_strncpy_setup(void) {
        void *buf = malloc(1024);
        cpakt_set_state(&test_strncpy_setup, buf);
    }

    void test_strncpy_teardown(void) {
        void *buf = cpakt_get_state(&test_strncpy_setup);
        free(buf);
    }

    void test_strncpy_1() {
        char *buf = cpakt_get_state(&test_strncpy_setup);
    }

    void test_strncpy_2() {
    }

You may compile and run this code using the command

    gcc -o first-test/test \
           first-test/test-main.c \
           first-test/test-strncpy.c -lcpakt_static
    ./first-test/test
