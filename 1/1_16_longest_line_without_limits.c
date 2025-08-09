#include <stdio.h>

#define MAXLINE 50

int getline_internal(char line[], int maxlen);

void copy(char to[], char from[]);

int imin(int a, int b) {
	if (a < b) return a;
	return b;
}

int main(void) {
	int len;
	int max;
	char line[MAXLINE];
	char longest [MAXLINE];

	max = 0;
	while ((len = getline_internal(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("%d => %s\n", max, longest);
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

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
