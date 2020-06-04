#include<stdio.h>
main()
{
   
    switch (printf("Hii"))
    {
    case 1:
        printf("hyderabad");
        break;

    case 2:
        printf("banglore");
        break;

    case 3:
        printf("chennai");
        break;
    
    default:
        printf("ranchi");
        break;
    }
}

//OPTIONS
//COMPILER ERROR
//hyderabad
//banglore
//chennai
//ranchi
//Hiichennai



//CORRECT OPTION- Hiichennai
//This is because printf() returns the no of characters of a string passed to it
//In this case 3 will be returned by printf("Hii");
//also using printf() in switch is completely valid