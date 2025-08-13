#include <stdio.h>
#include <assert.h>

/*
 * Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n 
 * bits that begin at position p set to the rightmost n bits of y, leaving 
 * the other bits unchanged.
 *
 * 1100110011 4 3 9
 * 
 * r
 * 1111111000
 * 0000000111
 *
 * c
 * 1111111111
 * 1111111000
 * 0000000111
 * 0000011100
 * 1111100011
 */
unsigned setbits(unsigned x, int p, int n, int y) {
	int replacement = ((~(~0 << n)) & y) << (p + 1 -n);;
	int clear = ~((~(~0 << n)) << (p +1 -n));
	return (x & clear) | replacement;
}

int main(void) {
	/* The number .....: 1100110011 */
	/* The positions ..: 9876543210 */
	assert(setbits(819, 4, 3, 819) == 815); /* The expected result: 1100101111 */
	assert(setbits(10, 3, 2, 7) == 14); /* x = 1010 y = 111, the expected result: 1110 */
	return 0;
}
