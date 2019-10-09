#include<stdio.h>
#include<string.h>

#define VALID_HEX_PREFIX (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
#define VALID_HEX_DIGIT (*hex < '0' || (*hex > '9' && *hex < 'A') || (*hex > 'F' && *hex < 'a') || *hex > 'f')

unsigned long hexToDecimal(char *hex, int length);
int validate(char *hex, int length);
int valueOf(char digit);

int main(void)
{
	char hex[17];
	int length;
	unsigned long decimal;
	scanf("%16s", hex);
	length = strlen(hex);
	if(validate(hex, length))
	{
		decimal = hexToDecimal(hex, length);
		printf("%s in hexadecimal is %lu in decimal\n", hex, decimal);
	}
	
	return 0;
}

unsigned long hexToDecimal(char *hex, int length)
{
	int i;
	unsigned long decimal = 0;
	unsigned long weight = 1;
	hex += length - 1;
	for(i = 0; i < length; ++i, --hex)
	{
		decimal += weight * valueOf(*hex);
		weight *= 16;
	}
	
	return decimal;
}

int validate(char *hex, int length)
{
    if(length > 2)
        if(VALID_HEX_PREFIX) // 0x or 0X
            hex += 2;
    while(*hex != '\0')
    {
        if(VALID_HEX_DIGIT)	//0-9 | A-F | a-f
        {
            printf("The input should be a hexadecimal number, containing only digits(0-9) and the first 6 letters(a-f).\n");
            return 0;
        }
        hex++;
    }
    
    return 1;
}

int valueOf(char digit)
{
    switch(digit)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A':
        case 'a': return 10;
        case 'B':
        case 'b': return 11;
        case 'C':
        case 'c': return 12;
        case 'D':
        case 'd': return 13;
        case 'E':
        case 'e': return 14;
        case 'F':
        case 'f': return 15;
		default: return 0;
    }
}
