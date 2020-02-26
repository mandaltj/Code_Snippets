#include <stdio.h>

int main(){
	unsigned char c = 0xFF;
	printf("Here: %x\n", c);

	char *msgs[2] = {
		"Hello",
		"Goodbye"
	};
	//From the following print statements we can say that
	//"msgs" is an array of 2 elements where each element is a pointer
	//to char. msgs[0] and msgs[1] are both pointers to char
	printf("Here: %s\n", msgs[0]);
	printf("Here: %s\n", msgs[1]);

	//In order to access individual char in the messages we need to dereference
	//msgs[0]/msgs[1] again with another []
	printf("Here: %c\n", msgs[0][1]);
	printf("Here: %c\n", msgs[1][1]);

	return 0;
}
