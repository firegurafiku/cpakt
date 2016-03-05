#include "cpakt/cpakt-asserts.h"
#include "cpakt/cpakt-main.h"

void cpakt_impl_assert_int_eq(
        int a, char const* acode,
	int b, char const* bcode,
        char const* file, int line) {
    
    if (a != b) {
	cpakt_fail_test("%d");
    }
}

// test runner:
// - execution
// - internal stdin stdout
// 
// output formatter:
// - event: begin
// - event: enter fixture
// - event: leave fixture
// - event: enter test
// - event: leave test
// - event: end
