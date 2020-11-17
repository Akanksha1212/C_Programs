#include <stdio.h> // Header file

int main() //main function
{
    int i, j, rows; // initalizaton of variables
    printf("Enter number of rows: ");
    scanf("%d", &rows); // Taking input from user

    // Nested for loop.....
    for (i=0; i<rows; i++)
    {
        for (j=0; j<(2*rows)-1; j++)
        {
            if (j>=(rows+1-i)&&j<=(rows-1+i))   // This is the condition to print the star
            {
                printf("* ");
            }
            else   // This is the condition to print the space
            {
                printf("  ");
            }
            
        }
        printf("\n");   // Printing new line character
    }

    return 0;
}
