#include<stdio.h>
main()
{
    int i=0;
    for(printf("Hii\n"); i<printf("ok\n"); printf("Namaste\n"))
    {
        printf("World: %d\n",i);
        i++;
    }
}

//CORRECT OUTPUT-
//Hii
//ok
//World: 0
//namaste
//ok
//World: 1
//namaste
//ok
//World: 2
//namaste
//ok


//this is because using printf() in initialisation, condition check and updation of for statement is completely valid
//also printf() returns the size of string contained in it
//Here in this case printf("ok\n") will return 2.
//Thus the condition check will be equivalent to i<2 