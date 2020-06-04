#include<stdio.h>
main()
{
    int i=1;

    switch(i)
    {
    case 1:
        printf("Hii ");
    default:
        printf("Bye");
    }    
}

//correct answer will be - Hii Bye as there is no break statement and both case 1 and
//default statement will be executed.




//A. compilation error
//B. Hii
//C. Hii Bye