#include<stdio.h>
#include<string.h>

unsigned long octalToDecimal(char *octal, int length);
int validate(char *octal, int length);

int main(void)
{
    char octal[23];
    int length;
    unsigned long decimal;

    scanf("%22s", octal);
    length = strlen(octal);
    if(validate(octal, length))
    {
        decimal = octalToDecimal(octal, length);
        printf("%s in octal is %lu in decimal\n", octal, decimal);
    }

    return 0;
}

unsigned long octalToDecimal(char *octal, int length)
{
    int i;
    unsigned long decimal = 0;
    unsigned long weight = 1;
    octal += length - 1;
    for(i = 0; i < length; ++i, --octal)
    {
        int coefficient = *octal - '0';
        decimal += weight * coefficient;
        weight *= 8;
    }

    return decimal;
}

int validate(char *octal, int length)
{
    while(*octal != '\0')
    {
        if(*octal < '0' || *octal > '7')
        {
            printf("The input should be an octal number, containing only digits(0-7).\n");
            return 0;
        }
        else
        {
            octal++;
        }
    }
    
    return 1;
}
