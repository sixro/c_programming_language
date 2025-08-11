#include <stdio.h>

/*
 * Returns celsius equivalent of specified temperature expressed in Fahrenheit
 */
float to_celsius(float fhar);

int main(void) {
	float fahr,celsius;
	float lower,upper,step;

	lower = 0;/* lower limit of temperatuire scale */
	upper = 300;/* upper limit */
	step = 20;/* step size */
	fahr = lower;
	
	printf("Farh  Celsius\n");
	
	while (fahr <= upper) {
		celsius = to_celsius(fahr);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr = fahr + step;
	}

	return 0;
}

float to_celsius(float fahr) {
	return (5.0/9.0) * (fahr-32.0);
}
