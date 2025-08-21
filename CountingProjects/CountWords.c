#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int countWords(char* input);
int main()

{

	char str1[16] = "   area   51 ";

	char str2[12] = "Hello World";

	char str3[17] = "Is this working?";

	char str4[10] = " \n ";



	printf("String '%s' has %d words.\n", str1, countWords(str1));

	printf("String '%s' has %d words.\n", str2, countWords(str2));

	printf("String '%s' has %d words.\n", str3, countWords(str3));

	printf("String '%s' has %d words.\n", str4, countWords(str4));



	return 0;

}

int countWords(char* input)
{
	unsigned int count = 0;
	bool beginning_of_next_word = false;
	for (unsigned int i = 0; input[i] != '\0'; i++) {
		if (!isspace(input[i])) {
			beginning_of_next_word = true;
		}
		if (isspace(input[i]) && beginning_of_next_word)
		{
			beginning_of_next_word = false;
			count++;
		}
	}
	if (beginning_of_next_word) {
		count++;
	}
	return count;
}