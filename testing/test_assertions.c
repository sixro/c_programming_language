#include "assertions.h"

void test_eq_int() {
	assert_eq(3, 3);
}

void test_eq_long() {
	assert_eq(4L, 4L);
}

int main(void) {
	/* Begin all tests */
	test_eq_int();
	test_eq_long();
	/* End all tests */
	return 0;
}
