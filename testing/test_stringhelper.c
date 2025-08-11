#include <stdio.h>
#include <string.h>

#include "stringhelper.h"

#include "assertions.h"

void test_left() {
	char src[] = "0123456789";
	char dest[5];
	strleft(dest, src, 4);
	assert_eqs("0123", dest);
}

void test_with_shorter_source() {
	char src[] = "01234";
	char dest[5];
	strleft(dest, src, 10);
	assert_eqs("01234", dest);
}

void test_empty() {
	char src[] = "";
	char dest[5];
	strleft(dest, src, 10);
	assert_eqs("", dest);
}

int main(void) {
	/* Begin all tests */
	test_empty();
	test_left();
	test_with_shorter_source();
	/* End all tests */
	return 0;
}
