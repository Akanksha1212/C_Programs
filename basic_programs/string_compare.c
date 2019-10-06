#include <stdio.h>
#include <string.h>

int main()
{
    char str1[32];
    char str2[32];
    
    // Ask for first string
    printf("Enter a string: ");
    fgets(str1, sizeof(str1), stdin);
    
    // Ask for second string
    printf("Enter another string: ");
    fgets(str2, sizeof(str2), stdin);

    // Print result
    printf("The strings are %s!", strcmp(str1, str2) == 0 ? "equal" : "not equal");

    return 0;
}
