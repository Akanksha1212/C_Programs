// *
// **
// ***
// ****
// ***
// **
// *
#include<stdio.h>
int main(){
    int n,i,j,k=0,mid;
    printf("Enter n");
    scanf("%d",&n);
    mid=(n+1)/2;
        for(i=1;i<=n;i++){
            if(n%2==0){
                if(i<=n/2){
                    k++;
                }
                if(i>n/2 +1){
                    k--;
                }
            }
            else{
            i<=mid?k++:k--;
            }
            for(j=1;j<=mid;j++){
                if(j<=k){
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
