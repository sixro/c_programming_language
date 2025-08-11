# testing

This is just an experiment I made to have tests written in C as if they are simple functions.  
The main idea is that there is a `main` containing everything you need to run the test (as globals).  
There are comments into which all the tests will be added by the `Makefile`.  
In the `Makefile` there is a command that is able to find all test methods (`test_*`) contained in the C files named `test_*.c`, add those tests inside the commented section, compile and run the test file.

Here the code inside the `Makefile`:

```
run-tests:
	@for file in $(TEST_FILES); do \
		tests=$$(grep -o 'test_[a-zA-Z0-9_]*' $$file | sort -u); \
		temp_calls="temp_calls_$$file"; \
		printf "" > $$temp_calls; \
		for test in $$tests; do \
			printf "\t%s();\n" "$$test" >> $$temp_calls; \
		done; \
		sed -i '' -e '/\/\* Begin all tests \*\//,/\/\* End all tests \*\//{//!d;}' $$file; \
		sed -i '' -e '/\/\* Begin all tests \*\//r '"$$temp_calls" $$file; \
		$(CC) $(CFLAGS) -o test_runner $$file $(ADDITIONAL_SOURCE_FILES); \
		if [ -f test_runner ]; then ./test_runner; fi; \
		rm -f test_runner $$temp_calls; \
	done
```

Here an example of the initial code:

```
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
	/* End all tests */
	return 0;
}
```

when the `run-tests` command of the `Makefile` is executed, the `main` function will become:

```
int main(void) {
	/* Begin all tests */
	test_empty();
	test_left();
	test_with_shorter_source();
	/* End all tests */
	return 0;
}
```
