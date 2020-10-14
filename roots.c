#include <stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d;
    double x1,x2;
    printf("enter the values of a b and c in a quadratic equation");
    scanf("%d %d %d",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if(d>0)
    {
        printf("\nthe roots are real and distinct");
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("\nthe roots are %lf and %lf",x1,x2);
    }
    else if(d==0)
    {
        printf("\nthe roots are real and equal");
        x1=(-b)/(2*a);
        x2=(-b)/(2*a);
        printf("\nthe roots are %lf and %lf",x1,x2);
    }
    else
    {
        printf("\nthe roots are imaginary");
        x1=-b/(2*a);
        x2=sqrt(-d)/(2*a);
        printf("\nthe roots are %lf+i%lf and %lf-i%lf",x1,x2,x1,x2);
    }
    return 0;
}