#include <stdio.h>

#define MAXLINE 100

int getline_internal(char line[], int maxlen);

int imin(int a, int b) {
	if (a < b) return a;
	return b;
}

int main(void) {
	int len;
	char line[MAXLINE];

	while ((len = getline_internal(line, MAXLINE)) > 0) {
		if (len > 80)
			printf("%s\n", line);
	}
	return 0;
}


int getline_internal(char s[], int s_size) {
	int c, i, lastidx;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < s_size -1) {
			s[i] = c;
		}
	}

	lastidx = imin(i, s_size -1);
	if (c == '\n') {
		s[lastidx] = c;
		++i;
	}
	s[lastidx] = '\0';
	return i;
}
