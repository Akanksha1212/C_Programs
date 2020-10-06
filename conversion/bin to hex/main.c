#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *binaryToHex(char *binary, int length);
char *padBinary(char *binary, int length);
int validate(char *hex, int length);
char valueOf(char *halfByte);

int main(void)
{
	char binary[97];
	int length;
	char *hex;
	int validation;
	
	scanf("%96s", binary);
	length = strlen(binary);
    validation = validate(binary, length);
	if(validation)
	{
		hex = binaryToHex(binary, length);
		printf("%s in binary is %sin hexadecimal\n", binary, hex);
	}
	
	return 0;
}

char *binaryToHex(char *binary, int length)
{
	int i;
	char *hex;
	char *paddedBinary = padBinary(binary, length);
	int hexLength = strlen(paddedBinary) / 4;	//	We need one hex symbol for every 4 binary symbols
	hexLength = hexLength + hexLength/2 + 1;	//	Make place for a space after every two symbols + the null terminater
	hex = (char *)malloc(hexLength);
	if(hex == NULL)
		exit(1);
	for(i = 0; i < length; i += 8)
	{
		char halfByte[5];
		// copy the 4 binary digits and decode them to one hex digit
		memcpy(halfByte, paddedBinary, 4);
		halfByte[4] = '\0';
		*hex++ = valueOf(halfByte);
		paddedBinary += 4;
		
		memcpy(halfByte, paddedBinary, 4);
		halfByte[4] = '\0';
		*hex++ = valueOf(halfByte);
		paddedBinary += 4;
		
		*hex++ = ' ';
	}
	*hex = '\0';
	hex -= hexLength - 1;
	
	return hex;
}

char *padBinary(char *binary, int length)
{
	int i;
	int padding = 8 - length % 8;
	int paddedBinaryLength = padding + length + 1;
	char *paddedBinary;
	if(padding == 8 || padding == 0)
		return binary;
	paddedBinary = (char *)malloc(paddedBinaryLength);
	if(paddedBinary == NULL)
		exit(1);
	for(i = 0; i < padding; ++i)
		*paddedBinary++ = '0';
	while(*binary != '\0')
		*paddedBinary++ = *binary++;
	*paddedBinary = '\0';
	paddedBinary -= paddedBinaryLength - 1;
	return paddedBinary;
}

int validate(char *binary, int length)
{
    while(*binary != '\0')
    {
        if(*binary == '0' || *binary == '1')
        {
            binary++;
        }
        else
        {
            printf("The input should be a hexadecimal number, containing only digits(0-9) and the first 6 letters(a-f).\n");
            return 0;
        }
    }
    
    return 1;
}

char valueOf(char *halfByte)
{
	if(strcmp(halfByte, "0000") == 0)
		return '0';
	if(strcmp(halfByte, "0001") == 0)
		return '1';
	if(strcmp(halfByte, "0010") == 0)
		return '2';
	if(strcmp(halfByte, "0011") == 0)
		return '3';
	if(strcmp(halfByte, "0100") == 0)
		return '4';
	if(strcmp(halfByte, "0101") == 0)
		return '5';
	if(strcmp(halfByte, "0110") == 0)
		return '6';
	if(strcmp(halfByte, "0111") == 0)
		return '7';
	if(strcmp(halfByte, "1000") == 0)
		return '8';
	if(strcmp(halfByte, "1001") == 0)
		return '9';
	if(strcmp(halfByte, "1010") == 0)
		return 'A';
	if(strcmp(halfByte, "1011") == 0)
		return 'B';
	if(strcmp(halfByte, "1100") == 0)
		return 'C';
	if(strcmp(halfByte, "1101") == 0)
		return 'D';
	if(strcmp(halfByte, "1110") == 0)
		return 'E';
	if(strcmp(halfByte, "1111") == 0)
		return 'F';
	return 0;
}
