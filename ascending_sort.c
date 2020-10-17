#include <stdio.h>

int main()
{
    int i, j, numbers[30], n, number;
    printf("Enter the value of N:");
    scanf("%d", &n);
    
    // adding the numbers to array
    for(i=1;i<=n;i++) {
        printf("Enter a number:");
        scanf("%d",&numbers[i]);
    }
    
    // sorting the numbers
    for(i=1;i<=n+1;i++) {
        for(j=i+1;j<=n;j++) {
            if(numbers[i] > numbers[j]) {
                number = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = number;
            }
        }
    }

    // displaying the sorted numbers 
    printf("The numbers in ascending order are:\n");
    
    for(i=1;i<=n;i++) {
        printf("%d\n",numbers[i]);
    }

    return 0;
}