#include<stdio.h>
#include<stdlib.h>

char *decimalToOctal(unsigned long decimal);

int main(void)
{
	unsigned long decimal;
	char *octal;
	scanf("%lu", &decimal);
	octal = decimalToOctal(decimal);
	printf("%lu in dec equals %s in octal\n", decimal, octal);

	return 0;
}

char *decimalToOctal(unsigned long decimal)
{
	char *octal = malloc(23);
	if(octal == NULL)
		exit(1);
	octal += 22;
	*octal-- = '\0';
	if(decimal == 0)
	{
		*octal = '0';
	}
	else
	{
		char remainder;
		while(decimal > 0)
		{
			remainder = (decimal % 8) + '0';
			*octal-- = remainder;
			decimal = decimal / 8;
		}
		octal++;
	}
	return octal;
}
