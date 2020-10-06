#include <stdio.h>
void main()
{
    char A[100];
    int i;
    printf("\nEnter A String\n");
    gets(A);
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 97 && A[i] <= 122)
        {
            A[i] = A[i] - 32;
        }

       
    }

    printf("This is the Answer\n%s", A);
}