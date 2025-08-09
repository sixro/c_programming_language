#include <stdio.h>

int main(void) {
	int c, printed_blank;

	printed_blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (! printed_blank) {
				printf(" ");
				printed_blank = 1;
			}
		}
		else {
			printed_blank = 0;
			printf("%c", c);
		}

	}
	return 0;
}
