#include<stdio.h>
main()
{
    int i=1;
    for( ; i<=3; )
    {
        printf("Hello world %d\n ", i);
        i++;
    }
}
//OPTIONS
// A. COMPILETIME ERROR
// B. Hello World 1
//    Hello World 2
//    Hello World 3


//correct answer - B. as keeping the initialisation and updation section of for loop blank is completely valid