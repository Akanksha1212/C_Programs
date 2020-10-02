#include <stdio.h>

int main()
{
    float firstTerm, diff, sum;
    int terms;
    
    printf("Enter the first term : ");
    scanf("%f\n", &firstTerm);
    printf("Enter the common difference : ");
    scanf("%f\n", &diff);
    printf("Enter the number of terms : ");
    scanf("%d\n", &terms);
    
    sum = terms*(2*firstTerm + (terms-1)*diff)/2;
    
    printf("Sum of AP : %f", sum);
    return 0;
}
