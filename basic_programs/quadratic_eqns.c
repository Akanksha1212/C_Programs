#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    double root1,root2;
    printf("enter a,b and c where a^x*x+b*x+c=0\n");
    scanf("%f%f%f",&a,&b,&c);
    root1= (-b+sqrt((b*b)-(4.0*a*c)))/2.0*a;
    printf("root1=%lf",root1);
    root2= (-b-sqrt((b*b)-(4.0*a*c)))/2.0*a;
    printf("root2=%lf",root1);
    return 0;
}
