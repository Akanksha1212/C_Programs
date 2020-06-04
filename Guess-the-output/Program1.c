#include<stdio.h>
#define x 5+2
int main()
{
    int i;
    i=x*x*x;
    //5+2*5+2*5+2
    //5+10+10+2

    printf("i is %d",i);
}

//x is an macro and it will just replace x with 5+2

// A. 343
// B. 27
// C. COMPILER ERROR
// D. 21

