#include<stdio.h>
main()
{
    int a=7;
    switch (a)
    {
    case 1:
    case 5:
    case 6:
        printf("hyderabad");
        break;
    case 2:
        printf("banglore");
        break;

    case 3:
    case 7:
    case 10:
        printf("chennai");
        break;
    
    default:
        printf("ranchi");
        break;
    }
}

//OPTIONS
//hyderabad
//banglore
//chennai
//ranchi

//CORRECT OPTION- chennai
//due to common actions of switch labels same statement will be executed if we enter 3,7 or 10 