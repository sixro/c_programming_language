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

int any(char s[], char chars[]) {
	int i;

	for (i = 0; s[i] != '\0'; i++) {
		if (contains(chars, s[i]))
			return i;
	}

	return -1;
}

int main (void) {
	int i = 0;
	char text[MAXLINE];
	char chars[MAXLINE];
	int pos;

	for (i = 0; i < MAXLINE; i++)
		text[i] = '\0';
	for (i = 0; i < MAXLINE; i++)
		chars[i] = '\0';

	i_getline(text, MAXLINE);
	i_getline(chars, MAXLINE);

	printf("Text ............: \"%s\"\n", text);
	printf("Chars ...........: \"%s\"\n", chars);

	pos = any(text, chars);
	printf("Position ........: %d\n", pos);
}
