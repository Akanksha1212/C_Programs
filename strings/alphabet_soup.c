//Take a string and place all the letter in alphabetical order

#include <stdio.h>

int string_length(char *string);
char *alphabet_soup(char *s, int n);

int main(void)
{
    signed char string[256];
    printf("Please write a word: ");
    fgets(string, 256, stdin);
    int n = string_length(string);

    char *s = alphabet_soup(string, n);
    printf("All the letters in alphabetical order: %s\n", s);

    return 0;
}

int string_length(char *string)
{
    int calcul;
    for(int i = 0; string[i] != '\0'; i++)
        calcul=i+1;

    return calcul;
}

char *alphabet_soup(char *s, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(s[i] > s[j])
            {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
    return s;
}
