/***************************SWAP WITHOUT THIRD VARIABLE********************************/

#include <stdio.h>

int main()
{
    int i,j;
    printf("Enter the i: ");
    scanf("%d",&i);
    printf("Enter the j: ");
    scanf("%d",&j);
    i=i-j;
    j=i+j;
    i = j-i;
    printf("i: %d\n",i);
    printf("j: %d\n",j);
    return 0;
}
