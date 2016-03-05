#ifndef CPAKT_ASSERTS_H_
#define CPAKT_ASSERTS_H_

#define CPAKT_ASSERT_INT_EQ(a, b) \
    cpakt_impl_assert_int_eq((a), #a, (b), #b, __FILE__, __LINE__)

#define CPAKT_ASSERT_INT_NE(a, b)
#define CPAKT_ASSERT_INT_LT(a, b) 
#define CPAKT_ASSERT_INT_LE(a, b) 
#define CPAKT_ASSERT_INT_GT(a, b) 
#define CPAKT_ASSERT_INT_GE(a, b) 

#define CPAKT_ASSERT_STR_EQ(a, b) 
#define CPAKT_ASSERT_STR_NE(a, b) 
#define CPAKT_ASSERT_STR_LT(a, b) 
#define CPAKT_ASSERT_STR_LE(a, b) 
#define CPAKT_ASSERT_STR_GT(a, b) 
#define CPAKT_ASSERT_STR_GE(a, b) 

#define CPAKT_ASSERT_NULL(ptr)
#define CPAKT_ASSERT_NOT_NULL(ptr)

#define CPAKT_ASSERT_TRUE(val)
#define CPAKT_ASSERT_FALSE(val)
#define CPAKT_ASSERT_THAT(val)

#define CPAKT_MESSAGE(fmt, ...)
#define CPAKT_DEBUG(fmt, ...)

void cpakt_impl_assert_int_eq(int a, char const* acode,
			      int b, char const* bcode,
			      char const* file, int line);


#endif
