#ifndef CPAKT_MAGIC_H_
#define CPAKT_MAGIC_H_

/** C preprocessor magic
    ====================

    To make test registration as simple as possible, Cpakt relies on C99's
    variadic macros. Unfortunately, C preprocessor is quite limited when it
    comes to advanced templating, so a big amount of magic was required to make
    things working. In particular, it was required to find a way to iterate
    over a variadic macro's arguments.

    In order not to reinvent a wheel, we decided to simply incorporate Jonathan
    Heathcote's implementation into the project as a separate file, prefixing
    all it's names with "CPAKT_MAGIC_". BTW, we asked Jonathan and he answered
    he is okay if we use his code under the MIT license.

    His original implementation is available on his website, accompanied with
    detailed explanation:

        http://jhnet.co.uk/articles/cpp_magic

    Important notes
    ---------------

    1. All names starting with "CPACK_MAGIC_" must be treated as internal; they
       must not be explicitly used by the library end users.

    2. Current implementation can process up to 1024 variadic arguments. So,
       the total number of test functions, test setup functions and test
       teardown functions must be less or equal to that number. */

#define CPAKT_MAGIC_EMPTY()
#define CPAKT_MAGIC_FIRST(a, ...) a
#define CPAKT_MAGIC_SECOND(a, b, ...) b

#define CPAKT_MAGIC_EVAL(...)     CPAKT_MAGIC_EVAL1024(__VA_ARGS__)
#define CPAKT_MAGIC_EVAL1024(...) CPAKT_MAGIC_EVAL512(CPAKT_MAGIC_EVAL512(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL512(...)  CPAKT_MAGIC_EVAL256(CPAKT_MAGIC_EVAL256(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL256(...)  CPAKT_MAGIC_EVAL128(CPAKT_MAGIC_EVAL128(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL128(...)  CPAKT_MAGIC_EVAL64(CPAKT_MAGIC_EVAL64(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL64(...)   CPAKT_MAGIC_EVAL32(CPAKT_MAGIC_EVAL32(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL32(...)   CPAKT_MAGIC_EVAL16(CPAKT_MAGIC_EVAL16(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL16(...)   CPAKT_MAGIC_EVAL8(CPAKT_MAGIC_EVAL8(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL8(...)    CPAKT_MAGIC_EVAL4(CPAKT_MAGIC_EVAL4(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL4(...)    CPAKT_MAGIC_EVAL2(CPAKT_MAGIC_EVAL2(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL2(...)    CPAKT_MAGIC_EVAL1(CPAKT_MAGIC_EVAL1(__VA_ARGS__))
#define CPAKT_MAGIC_EVAL1(...)    __VA_ARGS__

#define CPAKT_MAGIC_DEFER1(m) m CPAKT_MAGIC_EMPTY()
#define CPAKT_MAGIC_DEFER2(m) m CPAKT_MAGIC_EMPTY CPAKT_MAGIC_EMPTY()()
#define CPAKT_MAGIC_DEFER3(m) m CPAKT_MAGIC_EMPTY CPAKT_MAGIC_EMPTY CPAKT_MAGIC_EMPTY()()()
#define CPAKT_MAGIC_DEFER4(m) m CPAKT_MAGIC_EMPTY CPAKT_MAGIC_EMPTY CPAKT_MAGIC_EMPTY CPAKT_MAGIC_EMPTY()()()()

#define CPAKT_MAGIC_IS_PROBE(...) CPAKT_MAGIC_SECOND(__VA_ARGS__, 0)
#define CPAKT_MAGIC_PROBE() ~, 1

#define CPAKT_MAGIC_CAT(a,b) a ## b

#define CPAKT_MAGIC_NOT(x) CPAKT_MAGIC_IS_PROBE(CPAKT_MAGIC_CAT(CPAKT_MAGIC__NOT_, x))
#define CPAKT_MAGIC__NOT_0 CPAKT_MAGIC_PROBE()

#define CPAKT_MAGIC_BOOL(x) CPAKT_MAGIC_NOT(CPAKT_MAGIC_NOT(x))

#define CPAKT_MAGIC_IF_ELSE(condition) CPAKT_MAGIC__IF_ELSE(CPAKT_MAGIC_BOOL(condition))
#define CPAKT_MAGIC__IF_ELSE(condition) CPAKT_MAGIC_CAT(CPAKT_MAGIC__IF_, condition)

#define CPAKT_MAGIC__IF_1(...) __VA_ARGS__ CPAKT_MAGIC__IF_1_ELSE
#define CPAKT_MAGIC__IF_0(...)             CPAKT_MAGIC__IF_0_ELSE

#define CPAKT_MAGIC__IF_1_ELSE(...)
#define CPAKT_MAGIC__IF_0_ELSE(...) __VA_ARGS__

#define CPAKT_MAGIC_HAS_ARGS(...) CPAKT_MAGIC_BOOL(CPAKT_MAGIC_FIRST(CPAKT_MAGIC__END_OF_ARGUMENTS_ __VA_ARGS__)())
#define CPAKT_MAGIC__END_OF_ARGUMENTS_() 0

#define CPAKT_MAGIC_MAP(m, first, ...)                       \
  m(first)                                                   \
  CPAKT_MAGIC_IF_ELSE(CPAKT_MAGIC_HAS_ARGS(__VA_ARGS__))(    \
    CPAKT_MAGIC_DEFER2(CPAKT_MAGIC__MAP)()(m, __VA_ARGS__)   \
  )(                                                         \
    /* Do nothing, just terminate */                         \
  )
#define CPAKT_MAGIC__MAP() CPAKT_MAGIC_MAP

#endif
