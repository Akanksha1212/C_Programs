#include <stdio.h>
#include <stdlib.h>

int main()
{
     srand(time(0));
     int array[10];

     for(int i = 0; i<10; i++)
     {
         array[i] = rand()%30+1;
     }
     for(int i =0; i<10; i++)
        printf("%d\n",array[i]);
     printf("\n\n");


     int i,j,count,t;
         for(i=0; i<9; i++)
         {
             count =0;
             for(j=i+1; j<10; j++)
             {
                 if(array[i] > array[j])
                 {
                     t = array[i];
                     array[i] = array[j];
                     array[j] = t;
                     count++;
                 }}
                 if(count = 0)
                    break;
         }


     for(i =0; i<10; i++)
        printf("%d\n",array[i]);
}
