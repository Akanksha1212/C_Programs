#include<stdio.h>
#include<math.h>
int main ()
{
        int T,i=0,j=0,k=0;
        long double C,x,y,grad,pr=0.0001;

        scanf("%d",&T);
        for(k=1; k<=T; k++)
        {
        scanf("%Lf", &C);
        x=1;
        y = x*x + sqrt(x) - C;
        grad = 2*x + 1/(2*sqrt(x));

        for (x=1; fabs(y)>pr; i++)
        {
        x= x - y/grad;
        y =x*x + sqrt(x) - C;
        grad = 2*x + 1/(2*sqrt(x));
        i++;
        }
        printf("%Lf\n",x);
        }

        return 0;
}

