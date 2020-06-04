#include<stdio.h>
main()
{
    for(;;)
    {
        printf("Developers are really cool\n");
    }
}

//What will happen?
//COMPILETIME ERROR
//the loop will run infinite times
//loop will run 1 time

//correct answer- the loop will run infinite times
//as keeping all the sections(initialisation,condition,updation) of for loop blank is completely valid 