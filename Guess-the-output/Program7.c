#include<stdio.h>
main()
{
    int a=1;
    int b=2;
    switch (a)
    {
    case a:
        printf("hyderabad");
        break;

    case b:
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
//hyderabad
//banglore
//chennai
//ranchi
//COMPILER ERROR


//CORRECT OPTION- COMPILER ERROR
//CASE LABELS MUST BE VARIABLES IT CANNOT BE A VARIABLE LIKE a or b
//instead we can use const a , then error would not occur