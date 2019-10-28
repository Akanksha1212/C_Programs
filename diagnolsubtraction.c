#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j,a[3][3],sum1=0,sum2=0,difference;
    clrscr();
    for(i=0;i<3;i++)
    {
        printf("Enter a number");
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
        if(i==j)
        sum1=sum1+a[i][j];
        if((i+j)==2)
        sum2=sum2+a[i][j];
        }
    }
difference=sum1-sum2;
printf("The difference is=%d",difference);

}