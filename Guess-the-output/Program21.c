#include <stdio.h>
int main()
{
    int a = 1;
    int b = 1;
    int c = a || --b;
    int d = a-- && --b;
    printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
    return 0;
}
/*
Options:

A)a = 0, b = 1, c = 1, d = 0

B)a = 0, b = 0, c = 1, d = 0

C)a = 1, b = 1, c = 1, d = 1

D)a = 0, b = 0, c = 0, d = 0
*/
/*
Correct Answer:B)a = 0, b = 0, c = 1, d = 0
First the value of a is assigned 1 and b is assigned 1. Then c=a||--b, so here a is 1 and the operation is or so it will not check for --b.
b remains unchanged and c=1. Now d=a-- && --b. As this is logical and both will be checked. As it is a-- post decrement a will become 0 but that value will not be assigned to a in the operation.
So a remains 1 for the operation. Now as --b is pre decrement b will become 0 and it will be assigned so b=0 will be used in the operation.
so now d=1&&0 which is 0 so d=0.
Final answer a=0,b=0,c=1,d=0. 

*/