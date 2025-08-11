#ifndef ASSERTIONS_H
#define ASSERTIONS_H

#include <stdlib.h>

#define assert_eq(a, b) \
	if (a != b) { \
		fprintf(stderr, "%s:%d expected: %s but was: %s\n", __FILE__, __LINE__, #a, #b); \
		abort(); \
	}

#define assert_eqs(a, b) \
	if (strcmp(a, b) != 0) { \
		fprintf(stderr, "%s:%d expected: \"%s\" but was: \"%s\"\n", __FILE__, __LINE__, a, b); \
		abort(); \
	}

#endif /* ASSERTIONS_H */
