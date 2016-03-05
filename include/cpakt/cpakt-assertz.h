#ifndef CPAKT_ASSERTZ_H_
#define CPAKT_ASSERTZ_H_

#include "cpakt/cpakt-asserts.h"

#define assert_int_eq(a, b) CPAKT_ASSERT_INT_EQ(a, b) 
#define assert_int_ne(a, b) CPAKT_ASSERT_INT_NE(a, b) 
#define assert_int_lt(a, b) CPAKT_ASSERT_INT_LT(a, b) 
#define assert_int_le(a, b) CPAKT_ASSERT_INT_LE(a, b) 
#define assert_int_gt(a, b) CPAKT_ASSERT_INT_GT(a, b) 
#define assert_int_ge(a, b) CPAKT_ASSERT_INT_GE(a, b) 

#define assert_str_eq(a, b) CPAKT_ASSERT_STR_EQ(a, b) 
#define assert_str_ne(a, b) CPAKT_ASSERT_STR_NE(a, b) 
#define assert_str_lt(a, b) CPAKT_ASSERT_STR_LT(a, b) 
#define assert_str_le(a, b) CPAKT_ASSERT_STR_LE(a, b) 
#define assert_str_gt(a, b) CPAKT_ASSERT_STR_GT(a, b) 
#define assert_str_ge(a, b) CPAKT_ASSERT_STR_GE(a, b) 

#define assert_null(ptr)     CPAKT_ASSERT_NULL(ptr)
#define assert_not_null(ptr) CPAKT_ASSERT_NOT_NULL(ptr)

#define assert_true(val)     CPAKT_ASSERT_TRUE(val)
#define assert_false(val)    CPAKT_ASSERT_FALSE(val)
#define assert_that(val)     CPAKT_ASSERT_THAT(val)

#define message(fmt, ...)    CPAKT_MESSAGE(fmt, __VA_ARGS__)
#define debug(fmt, ...)      CPAKT_DEBUG(fmt, __VA_ARGS__)

#endif
