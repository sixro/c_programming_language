#include <stdio.h>

#define TABSIZE 4

int main(void) {
	int c, i;
	char spaces[TABSIZE +1];

	for (i = 0; i < TABSIZE; i++)
		spaces[i] = ' ';
	spaces[TABSIZE] = '\0';

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("%s", spaces);
		else
			printf("%c", c);
	}
	return 0;
}
