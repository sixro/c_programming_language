#include <stdio.h>

#include <string.h>

void strleft(char *dest, char *src, int len) {
	int srclen = strlen(src);

	if (srclen < len)
		len = srclen;

	dest[len] = '\0';
	while (--len >= 0)
		dest[len] = src[len];
}
