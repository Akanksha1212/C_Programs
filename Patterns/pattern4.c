// *****
//  ****
//   ***
//    **
//     *
#include<stdio.h>
int main(){
    int n,i,j,k;
    printf("Enter n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf(" ");
        }
        for(k=(n-i+1);k>=1;k--){
            printf("*");
        }
        printf("\n");
    }
    
}