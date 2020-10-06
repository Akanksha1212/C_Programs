4. //Program to Print Square
#include<stdio.h>
#include<conio.h>
void main()
{
int a,b;
clrscr();
for(a=1;a<=3;a++)
{
for (b=1;b<=a;b++)
{
if(a==2&&b==2)
{
printf(" ");
}
else
{
printf("*");
}
}
for(b=(3-a);b>=1;b--)
{
printf("*");
}
printf("\n");
}
getch();
}