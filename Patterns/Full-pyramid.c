#include <stdio.h>

int main()
{
    int row;
    scanf("%d",&row);
    for(int i=0;i<row;i++){
        for(int j=1;j<=2*row;j++){
            if(j>=row-i&&j<=row+i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
