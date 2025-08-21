#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
unsigned char NumberObBits(int n)
{
	unsigned char count = 0;
	while (~n > 0)
	{
		n >>= 1;
		count++;
	}
	return count+1;
}

bool* BinaryForm(int input)
{
	unsigned char n = NumberObBits(input);
	//printf("%d", n); to see how many bits
	bool* ptr = (bool*)malloc(sizeof(bool) * n);
	assert(ptr != NULL);
	for (char i = n - 1; i >= 0; i--) { //Missed the equals to
		if (input & 1 == 1) {
			*(ptr + i) = true;
		}
		else {
			*(ptr + i) = false;
		}
		input >>= 1;
	}
	return ptr;
}

int main()
{
	int n = 312;
	bool* test = BinaryForm(n);

	unsigned char count = NumberObBits(n);

	for (unsigned char i = 0; i < count; i++) {
		printf("%u", *(test + i));
	}
	free(test);
	return 0;
}