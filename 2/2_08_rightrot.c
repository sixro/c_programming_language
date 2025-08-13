#include <stdio.h>
#include <assert.h>

/*
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of 
 * the integer x rotated to the right by n positions.
 */
unsigned rightrot(unsigned x, int n) {
	int mask = x << (32 - n);
	return (x >> n) | mask;
}

int main(void) {
	printf("Size of int: %d\n", sizeof(int));
	assert(rightrot(1, 1) == 2147483648);
	assert(rightrot(2147483648, 1) == 1073741824);
	return 0;
}
