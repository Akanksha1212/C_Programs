#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INVALID_INPUT 0
#define VALID_INPUT 1
#define VALID_PREFIX 3

char *hexToBinary(char *hex, int validation, int length);
int validate(char *hex, int length);
char *valueOf(char digit);

int main(void)
{
	char hex[101];
	int length;
	int validation;
	char *binary;

	scanf("%100s", hex);
	length = strlen(hex);
    validation = validate(hex, length);
	if(validation)
	{
		binary = hexToBinary(hex, validation, length);
		printf("%s in hexadecimal is %sin binary\n", hex, binary);
	}
	
	return 0;
}

char *hexToBinary(char *hex, int validation, int length)
{
	char *binary = (char*) malloc(length * 5 + 1);
	if(binary == NULL)
		exit(1);
	if(validation == VALID_PREFIX)
	{
		hex += 2;
		length -= 2;
	}
	while(*hex != '\0')
	{
		char *binaryValue = valueOf(*hex);
		while(*binaryValue != '\0')
			*binary++ = *binaryValue++;
		++hex;
	}
	*binary = '\0';
	binary -= length * 5;
	return binary;
}

int validate(char *hex, int length)
{
    int result = VALID_INPUT;
    if(length > 2)
    {
        if(hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        {
            hex += 2;
            result = VALID_PREFIX;
        }
    }
    while(*hex != '\0')
    {
        if(*hex < '0' || (*hex > '9' && *hex < 'A') || (*hex > 'F' && *hex < 'a') || *hex > 'f')
        {
            printf("The input should be a hexadecimal number, containing only digits(0-9) and the first 6 letters(a-f).\n");
            result = INVALID_INPUT;
            break;
        }
        else
        {
            hex++;
        }
    }
    
    return result;
}

char *valueOf(char digit)
{
    switch(digit)
    {
        case '0': return "0000 ";
        case '1': return "0001 ";
        case '2': return "0010 ";
        case '3': return "0011 ";
        case '4': return "0100 ";
        case '5': return "0101 ";
        case '6': return "0110 ";
        case '7': return "0111 ";
        case '8': return "1000 ";
        case '9': return "1001 ";
        case 'A':
        case 'a': return "1010 ";
        case 'B':
        case 'b': return "1011 ";
        case 'C':
        case 'c': return "1100 ";
        case 'D':
        case 'd': return "1101 ";
        case 'E':
        case 'e': return "1110 ";
        case 'F':
        case 'f': return "1111 ";
        default:
        {
            printf("Cannot decode that symbol: %c" + digit);
            return 0;
        }
    }
}
