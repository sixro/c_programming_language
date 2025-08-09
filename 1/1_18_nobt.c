#include <stdio.h>

#define MAXLINE 1000

#define IN  1
#define OUT 0

int getline_internal(char line[], int maxline);

void copy(char to[], char from[]);

/*
 * WARNING: I am not completely sure the exercise is correct, because it saying
 * that I have to remove traling spaces and tabs, but I consider both in the
 * algo to skip them... so, maybe it's wrong
 */
int main(void) {
	int len;
	char line[MAXLINE];

	while ((len = getline_internal(line, MAXLINE)) > 0) {
		if (len > 1)
			printf("%s", line);
	}
	return 0;
}


int getline_internal(char s[], int lim) {
	int c, i;
	int state;

	state = OUT;
	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		if (c == ' ' || c == '\t') {
			if (state == IN) {
				s[i] = c;
			} else {
				/* go back with the counter to remove the traling characters */
				i--;
			}
			state = OUT;
		}
		else {
			if (state == OUT) {
				state = IN;
			}
			s[i] = c;
		}	
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
