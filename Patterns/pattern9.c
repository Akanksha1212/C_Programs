// 1
// 12
// 123
// 1234
// 12345
#include<stdio.h>
int main(){
    int n,i,j,initial;
    printf("Enter n");
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        initial=1;
        for(j=1;j<=i;j++){
            printf("%d\t",initial++);
        }
        printf("\n");
    }
}