// *******
//  *****
//   ***
//    *

#include<stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter number");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf(" ");
        }
        for(k=i;k<=(2*n-i);k++){
            printf("*");
        }
        printf("\n");
    }
}