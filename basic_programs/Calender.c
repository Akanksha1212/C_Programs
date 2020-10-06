#include <stdio.h>
#include <math.h>
int main()
{
        int a,b,c,d,e;
        printf("Hello you are in Calender, enter a year and you will able to see the day of its 1st january\n\n");
        scanf("%d",&a);
        b=fabs(a-1900);
        c=b/4;
        d=b+c;
        e=d%7;
        if(a%4!=0)
        {

        if(e==0)
                printf("Monday\n");
        if(e==1)
                printf("Tuesday\n");
        if(e==2)
                printf("Wednesday\n");
        if(e==3)
                printf("Thursday\n");
        if(e==4)
                printf("Friday\n");
        if(e==5)
                printf("Saturday\n");
        if(e==6)
                printf("Sunday\n");}

        else
        {       e=(d%7)-1;
        if(e==0)
                printf("Monday\n");
        if(e==1)
                printf("Tuesday\n");
        if(e==2)
                printf("Wednesday\n");
        if(e==3)
                printf("Thursday\n");
        if(e==4)
                printf("Friday\n");
        if(e==5)
                printf("Saturday\n");
        if(e==6)
                printf("Sunday\n");}

        return 0;
} 
