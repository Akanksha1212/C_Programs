//     1
//    121
//   12321
//  1234321
// 123454321

#include<stdio.h>
int main(){
    int i,j,n;
    printf("Enter the value of n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int initial=1;
        for(j=1;j<=(2*n-1);j++){
            if(j>=(n-i+1)&&j<=(n+i-1)){
                printf("%d",initial);
                j<n?initial++:initial--;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}