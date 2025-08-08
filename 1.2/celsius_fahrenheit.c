#include <stdio.h>

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
		fahr = (celsius * (((float) 9) / 5)) + 32;
		printf("%3.0f       %3.0f\n", celsius, fahr);

		celsius += step;
	}

	return 0;
}
