#include <stdio.h>

#define CHARS 127

int main(void) {
	int c, i, j;
	int cf[CHARS]; /* array of char frequencies */

	/* Initialize the array of lengths */
	for (i = 0; i < CHARS; i++)
		cf[i] = 0;

	while ((c = getchar()) != EOF)
		cf[c]++;

	for (i = 0; i < CHARS; i++) {
		/* skip chars that didn't appear */
		if (cf[i] == 0) continue;

		/* print special characters in an unambiguous way */
		if (i == '\t') printf("'\\t' => ");
		else if (i == '\n') printf("'\\n' => ");
		else printf("'%c'  => ", (char) i);

		/* print histogram for this char */
		for (j = 0; j < cf[i]; j++)
			printf("*");
		printf("\n");
	}

	return 0;
}
