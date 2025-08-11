#include <stdio.h>

#include <limits.h>
#include <float.h>

int main (void) {
	printf("char ............: %20d <-> %u\n", CHAR_MIN, CHAR_MAX);
	printf("char unsigned ...: %20d <-> %u\n", 0, UCHAR_MAX);
	printf("short ...........: %20d <-> %u\n", SHRT_MIN, SHRT_MAX);
	printf("short unsigned ..: %20d <-> %u\n", 0, USHRT_MAX);
	printf("int .............: %20d <-> %u\n", INT_MIN, INT_MAX);
	printf("int unsigned ....: %20d <-> %u\n", 0, UINT_MAX);
	printf("long ............: %20ld <-> %lu\n", LONG_MIN, LONG_MAX);
	printf("long unsigned ...: %20d <-> %lu\n", 0, ULONG_MAX);

	char signed_char_max = (char) ((unsigned char) ~ 0 >> 1);
	char signed_char_min = (char) ((unsigned char) ~ 0 << (sizeof(char) * 8 -1));

	printf("COMPUTED\n");
	printf("char ............: %20d <-> %u\n", signed_char_min, signed_char_max);
	/* ... OK, you know the rest */
	return 0;
}
