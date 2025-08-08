#include <stdio.h>

#define FARH_OFFSET 32
#define FARH_CONVERSION_FACTOR ((float) 9) / 5

int main(void) {
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;
	upper = 150;
	step = 10;

	/* print the header */
	printf("Celsius   Fahrenheit\n");

	celsius = lower;
	while (celsius < upper) {
		fahr = celsius * FARH_CONVERSION_FACTOR + FARH_OFFSET;
		printf("%3.0f       %3.0f\n", celsius, fahr);

		celsius += step;
	}

	return 0;
}
