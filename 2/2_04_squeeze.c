#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int i_getline(char dest[], int maxlen) {
	int i;
	char c;

	for (i=0; i < maxlen - 1; ++i) {
		c = getchar();
		if (c == '\n' || c == EOF)
			break;
		dest[i] = c;
	}
	dest[i] = '\0';
	return i;
}

int contains(const char s[], char c) {
	int k;
	int found = 0;
	for (k = 0; s[k] != '\0'; k++) {
		if (s[k] == c) {
			found = 1;
			break;
		}
	}
	return found;
}

void squeeze(char s[], char chars[]) {
	int i, j, k;

	for (i = j = 0; s[i] != '\0'; i++) {
		if (! contains(chars, s[i]))
			s[j++] = s[i];
	}
	s[j] = '\0';
}

int main (void) {
	int i = 0;
	char text[MAXLINE];
	char to_squeeze[MAXLINE];

	for (i = 0; i < MAXLINE; i++)
		text[i] = '\0';
	for (i = 0; i < MAXLINE; i++)
		to_squeeze[i] = '\0';

	i_getline(text, MAXLINE);
	i_getline(to_squeeze, MAXLINE);

	printf("Text ............: \"%s\"\n", text);
	printf("To squeeze ......: \"%s\"\n", to_squeeze);

	squeeze(text, to_squeeze);
	printf("Squeezed ........: \"%s\"\n", text);
}
