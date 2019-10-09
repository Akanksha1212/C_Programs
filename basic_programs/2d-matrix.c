#include <stdio.h>

int main()
{
    int r,c;
    printf("enter row number and column number");
    scanf("%d%d,&r,&c);
     int arr[500][500];
    for(int i=0;i<r;i++)
          {
              for(int j=0;j<c;j++)
              {
                  printf("Enter %d x %d element",i,j);
                  scanf("%d",&arr[i][j]);
              }
          }
     printf(" the 2D matrix is =");
          for(int i=0;i<r;i++)
          {
              for(int j=0;j<c;j++)
              {
                  printf("%d",arr[i][j]);
              }
          }
          
    return 0;
}
