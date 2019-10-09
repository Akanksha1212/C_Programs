#include<stdio.h>
#include<stdlib.h>

char* decimalToHex(unsigned long decimal);
char remainderToHex(int remainder);

int main(void)
{
	unsigned long decimal;
	char* hex;
	printf("Enter a decimal number: ");
	scanf("%lu", &decimal);
	hex = decimalToHex(decimal);
	printf("%lu in decimal equals %s in hexadecimal", decimal, hex);
	
	return 0;
}

char* decimalToHex(unsigned long decimal)
{
	char *hex = (char *)malloc(17);
	if(hex == NULL)
		exit(1);
	hex += 16;
	*hex = '\0';
	if(decimal == 0)
	{
		--hex;
		*hex = '0';
	}
	else
	{
		char remainder;
		while(decimal > 0)
		{
			--hex;
			remainder = remainderToHex(decimal % 16);
			*hex = remainder;
			decimal = decimal / 16;
		}
	}
	return hex;
}

char remainderToHex(int remainder)
{
	if(remainder >=0 && remainder <=9)
		return remainder + '0';
	else
		return remainder - 10 + 'A';	//if(remainder >= 10 && remainder <= 15)
}
