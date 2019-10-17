#include<stdio.h>
int main()
{
    int i,j,n;
    char a;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        a='Z';
        for(j=1;j<=i;j++)
        {
            printf("%c",a-i+1);
            a++;
        }
        a='Z';
        for(j=1;j<=i-1;j++)
        {
            printf("%c",a-1);
            a--;
        }
        printf("\n");
    }
    for(i=1;i<=n-1;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf(" ");
        }
        a='Z';
        for(j=1;j<=(n-i);j++)
        {
           printf("%c",a-n+i+1);
           ++a;
        }
       a='Z';
        for(j=1;j<=(n-i-1);j++)
        {
            printf("%c",a-j);
           // a--;
        }
        printf("\n");
    }
    return 0;
}
