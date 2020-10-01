//     *
//    ***
//   *****
//  *******
//   *****
//    ***
//     *

#include<stdio.h>
int main(){
    int n,i,j,k=0,mid;
    printf("Enter n");
    scanf("%d",&n);
    mid=(n+1)/2;
      
    for(i=1;i<=n;i++){
        if(n%2==0){
            if(i<=mid){
                k++;
            }
            if(i>mid+1){
                k--;
            }
        }
        else
        {
            i<=mid?k++:k--;
        }
        for(j=1;j<=n;j++){
            if(j>=(mid-k+1) && j<=(mid+k-1)){
                printf("*");
            }
            else
            {
                printf(" ");
            }
           }
           printf("\n");
    }  
}