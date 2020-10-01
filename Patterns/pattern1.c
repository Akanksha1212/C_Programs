// *
// **
// ***
// ****
// *****
#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}