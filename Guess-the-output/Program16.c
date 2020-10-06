#include<stdio.h>
main()
{
    int i=1;
    for(printf("Hii\n"); i<=3; i++)
    {
        printf("Hello world %d\n", i);
    }
}

//CORRECT ANSWER-
//Hii
//Hello world 1
//Hello world 2
//Hello world 3

//using printf() in initialisation of for loop is completely valid