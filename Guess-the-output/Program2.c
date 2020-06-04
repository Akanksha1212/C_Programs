#include<stdio.h>
main()
{
    int n=65;
    switch(n)
    {
        case 64:
            printf("case 64\n");
            break;
        case 'A':
            printf("case A\n");
            break;
        default:
        printf("default case\n");        
    }
}
//CORRECT ANSWER - case A 
//char to int and viceversa automatic type casting is done
//As ASCII value of A is 65 case A will be the correct output



//A. case 64
//B. case A
//default case
//D. compiler error