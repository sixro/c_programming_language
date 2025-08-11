#include <stdio.h>

#include "stringhelper.h"

int main(void) {
	char dest[10];
	char src[] = "Hello, World!";
	
	printf("%s\n", src);

	strleft(dest, src, 5);

	printf("Left(5): \"%s\"\n", dest);
	return 0;
}
