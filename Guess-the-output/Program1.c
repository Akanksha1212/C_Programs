#include<stdio.h>
#define x 5+2  //x is a macro and it will just replace x with 5+2
int main()
{
    int i;
    i=x*x*x; // HINT: Use Bodmas rule and the precedence
    printf("Value of i is %d\n",i);
}

// A. 343
// B. 27
// C. COMPILER ERROR
// D. 21

