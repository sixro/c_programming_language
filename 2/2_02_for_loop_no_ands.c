#include <stdio.h>

#define MAXLINE 100
int main (void) {
	int i;
	int lim;
	char c;
	char dest[MAXLINE];

	for (i = 0; i < MAXLINE; i++)
		dest[i] = '\0';

	lim = MAXLINE;
	/*for (i=0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; ++i) {*/
	for (i=0; i < lim - 1; ++i) {
		c = getchar();
		if (c == '\n' || c == EOF)
			break;
		dest[i] = c;
	}

	printf("Text: \"%s\"\n", dest);
}
