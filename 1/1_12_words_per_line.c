#include <stdio.h>

#define IN  1 /* inside a word */
#define OUT 0 /* outside a word */

int main(void) {
	int c, state;

	state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN)
				printf("\n");
			state = OUT;
		}
		else {
			if (state == OUT)
				state = IN;
			printf("%c", c);
		}
	}

	return 0;
}
