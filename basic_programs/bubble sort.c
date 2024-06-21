#include <stdio.h>
#include <stdlib.h>

int main()
{
    //input in array
    int n;
    printf("enter no of elements in array\t");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter elements respectively\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

     //algorithm for bubble sort

     int count = 0, i,j,t;

     while(1)
     {
         count = 0;
         for(i=0; i<n; i++)
         {
             if(arr[i]<arr[i+1])
             {
                 t = arr[i];
                 arr[i] = arr[i+1];
                 arr[i+1] = t;
                 count++;
             }


         }if(count==0)
                break;
     }

     //output
     for(i =0; i<n; i++)
        printf("%d\n",arr[i]);
}
