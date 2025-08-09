#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main(void) {
	int c, printed_blank;

	printed_blank = FALSE;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (! printed_blank) {
				printf(" ");
				printed_blank = TRUE;
			}
		}
		else {
			printed_blank = FALSE;
			printf("%c", c);
		}

	}
	return 0;
}
