#include<stdio.h>
main()
{
   
    switch (5)
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
    
    
    }
}

//OPTIONS-
//COMPILER ERROR: Default missing
//Empty output screen with success compilation and execution
//COMPILER ERROR: Case 5 unavailable
//chennai

//CORRECT ANSWER- Empty output screen with success compilation and execution
// default statement in switch case is completely optional
