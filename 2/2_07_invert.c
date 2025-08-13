#include <stdio.h>
#include <assert.h>

/*
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n 
 * bits that begin at position p inverted (i.e., 1 changed into 0 and 
 * viceversa), leaving the others unchanged.
 */
unsigned invert(unsigned x, int p, int n) {
	int mask = (~(~0 << n)) << (p +1 -n);
	return x ^ mask;
}

int main(void) {
	assert(invert(10, 2, 2) == 12); /* x = 1010 , the expected result: 1100 */
	return 0;
}
