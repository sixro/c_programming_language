#include <stdio.h>
#include <assert.h>

unsigned bitcount(unsigned x) {
	int i = 0;
	while (x > 0) {
		x &= (x -1);
		i++;
	}
	return i;
}

int main(void) {
	assert(bitcount(7) == 3);
	return 0;
}
