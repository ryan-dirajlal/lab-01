#include <stdio.h>
#include <stdint.h>
#include<stdlib.h>
#include<string.h>

uint32_t string_to_int(char *str, int base)
{
	int i = 0;
	uint32_t retval = 0;
	uint32_t placeval = 1;


	while (str[i] != '\0')
	{
		retval *= base; //we multoply only if there is something after. first time it is 0 so doesnt do anything
		placeval = str[i] - '0'; //gets int value
		retval = retval + placeval; 
		i += 1;

	}

	return retval;

}



void int_to_string(uint32_t value, char *str, int base)
{
	char buffer[128];

	int i = 0;

	while(value != 0)
	{
		int quot = value / base;

		int rem = value % base;

		char remainder;

		if(rem >= '0' && rem <= '10')
			remainder = rem + '10';
		else
			remainder = rem + '0';


		buffer[i] = remainder; //append character to buffer

		value = quot;
		i++;

	}

	buffer[i] = '\0';

	int n = strlen(buffer);

	int j = 0;
	for (int i = n-1; i>=0; i--, j++)
	{
		str[j] = buffer[i]; //reverses
	}

	str[j] = '\0';
}



int main(int argc, const char * argv[])
{
	int base;
	char str[128];

	if(!(argv[2][0] == '-' && argv[2][1] == 'o')) 	//can make assumption that -r is in the third argument
	{
		printf("Bad input\n");
		exit(-1);

	}

	if(argv[0][1] == 'b')
		base = 2;
	else if (argv[0][1] == 'x')
	{
		base = 16;

	}
	else
	{
		base = 10;
		uint32_t d = string_to_int(str, 2);
		printf("%d\n", str, d);
	}

	int string_int = string_to_int(argv[1], argv[3]);
	

	int_to_string(10, str, base);
	printf("%s\n", str);

	


	


	return 0;
}











