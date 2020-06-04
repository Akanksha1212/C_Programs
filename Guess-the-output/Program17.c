#include<stdio.h>
main()
{
    int i=1;
    for(printf("Hii\n"); i<=3; printf("Hello\n"))
    {
        i++;
    }
}

//CORRECT output-
//Hii
//Hello
//Hello

//using printf() in initialisation and updation section of for loop is completely valid