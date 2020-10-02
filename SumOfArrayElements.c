#include<stdio.h>
void main()
{
    int n;
    printf("Enter no. of elements in array: ");
    scanf("%d", &n);
    int arr[n],count=0,i;
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++)
    {
        count = count + arr[i];
    }
    printf("Sum is: %d", count);
}
