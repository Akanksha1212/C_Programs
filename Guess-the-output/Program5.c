#include<stdio.h>
main()
{
    int i=1;        //i=1
    i++;            //i=2;
    switch(i--)     //i-- =2 , i=1
    {
        case 1:
            printf("case 1");
            break;
        case 2:
            printf("case 2");
            break;
        default:
            printf("default block");
            break;
    }
}

//OPTIONS
// A. case 1
// B. case 2
// C. default block
// D. COMPILATION ERROR


//CORRECT ANSWER- B. case 2
// as value of i-- will be 2 because it is a post-decreement operator 