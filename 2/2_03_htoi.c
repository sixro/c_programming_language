#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int htoic(char c) {
	int tmp;
	if (c >= '0' && c <= '9')
		tmp = c - '0';
	else if (c >= 'a' && c <= 'f')
		tmp = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		tmp = c - 'A' + 10;
	return tmp;
}

int htoi(const char hex[]) {
	int i;
	int tmp;
	int l = strlen(hex);
	int val = 0;
	unsigned int exp;

	for (i = l -1, exp = 1; i >= 0; i--, exp <<= 4) {
		tmp = htoic(hex[i]);
		val += tmp * exp;
	}

	return val;
}

int main (void) {
	int i;
	int lim;
	int converted;
	char c;
	char dest[MAXLINE];

	for (i = 0; i < MAXLINE; i++)
		dest[i] = '\0';

	lim = MAXLINE;
	for (i=0; i < lim - 1; ++i) {
		c = getchar();
		if (c == '\n' || c == EOF)
			break;
		dest[i] = c;
	}

	printf("Hex ............: %s\n", dest);

	converted = htoi(dest);
	printf("Converted int ..: %d", converted);
}
