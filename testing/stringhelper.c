#include <stdio.h>

void strleft(char *dest, char *src, int len) {
	dest[len] = '\0';
	while (--len >= 0)
		dest[len] = src[len];
}
