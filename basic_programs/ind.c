#include<stdio.h>
#include<string.h>
int main () {
        char a[1000000];
        int t,max,c,i,j,l;
        scanf ("%d",&t);
        for (j=0;j<t;j++)
        {
                scanf("%s",a);
                l=strlen(a);

                max=0;
                c=0;
                for (i=0;i<l;i++)
                {
                        if (a[i]=='(')
                        c=c+1;

                        else
                        c=c-1;

                        if(c>max)
                        max=c;
                }

                printf("%d\n",max);
        }
        return 0;
}


