#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n;
     int array[10];

     for(int i = 0; i<10; i++)
     {
         array[i] = rand()%30+1;
         printf("%d\n",array[i]);
     }

     printf("\n\n");



     int mark = 1,i,j,t;
     for(i=1; i<10; i++)
     {
         for(j=0; j<i; j++)
         {
             if(array[i] < array[j])
             {
                 for(int k=i; k>j; k--)
                 {
                     t = array[k];
                     array[k] = array[k-1];
                     array[k-1] = t;
                 }
             }
         }
     }



     for(i =0; i<10; i++)
        printf("%d\n",array[i]);
}
