#include <stdio.h>
int main()
{
    int a[100],i,j,n,temp=0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i= 0;i<n;i++)
    {
        for (j= 0;j<i; j++)
        {
            if (a[i]<a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("bubble sort");
    for (i=0;i<n;i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
