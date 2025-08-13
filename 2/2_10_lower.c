#include <stdio.h>
#include <assert.h>
#include <string.h>

void lower(char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++)
		s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] + 'a' - 'A') : s[i];
}

int main(void) {
	char s[] = "WoRlD";
	lower(s);
	assert(strcmp(s, "world") == 0);
	return 0;
}
