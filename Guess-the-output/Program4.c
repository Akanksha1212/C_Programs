#include<stdio.h>
main()
{
    int i=65;

    switch(i)
    {
        case 65:
            printf("case 65");
            break;
        case 'A':
            printf("case A");
            break;
        default:
            printf("Bye ");
    }
}


//OPTIONS
// A. case 65
// B. case A
// C. Bye
// D. COMPILATION ERROR



//CORECT ANSWER- COMPILATION ERROR as there is duplicate switch labels 
//DUE TO TYPE CASTING 'A' WILL BE CONVERTED TO 65 ALSO 65 IS ALREADY PRESENT