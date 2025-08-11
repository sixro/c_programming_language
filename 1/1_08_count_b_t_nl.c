#include <stdio.h>

int main(void) {
	int c, blanks, tabs, nl;

	blanks = 0;
	tabs = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blanks;
		else if (c == '\t')
			++tabs;
		else if (c == '\n')
			++nl;
	}

	printf("Blanks: %d, Tabs: %d, Newlines: %d\n", blanks, tabs, nl);

	return 0;
}
