#include <stdio.h>

int main()
{
    int x;
    int power = 1;
    int y = 0;
    
    printf("Enter the decimal number: ");
    scanf("%d",&x);
    
    do{
        int rem = x % 2;
        y = rem * power + y;
        x /= 2;
        power *= 10;
    }
    while(x != 0);
    
    printf("The binary equivalent is: %d\n", y);
    
    return 0;
}
