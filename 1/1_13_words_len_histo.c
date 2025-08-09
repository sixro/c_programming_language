#include <stdio.h>

#define IN  1
#define OUT 0

#define LENGTHS 20

int main(void) {
	int c, i, j, state, wl;
	int lens[LENGTHS]; /* array of lengths */

	/* Initialize the array of lengths */
	for (i = 0; i < LENGTHS; i++)
		lens[i] = 0;

	wl = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state == IN) {
				lens[wl - 1]++;
				wl = 0;
			}
			state = OUT;
		}
		else {
			if (state == OUT)
				state = IN;
			wl++;
		}
	}

	for (i = 0; i < LENGTHS; i++) {
		if (lens[i] == 0) continue;

		printf("%2d => ", i + 1);
		for (j = 0; j < lens[i]; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
