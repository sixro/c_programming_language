#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "stringhelper.h"

void test_left() {
	char src[] = "0123456789";
	char dest[5];
	strleft(dest, src, 4);
	assert(strcmp(dest, "0123") == 0);
}

int main(void) {
	test_left();
	return 0;
}
