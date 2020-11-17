// ABCDCBA
// ABC CBA
// AB   BA
// A     A
#include<stdio.h>
int main(){
    int n,i,j;
    printf("Enter n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        char ch='A';
        for(j=1;j<=(2*n-1);j++){
            if(j<=(n-i+1)||j>=(n+i-1)){
                printf("%c",ch);
                j<n?ch++:ch--;
            }
            else
            {
                printf(" ");
                if(j==n)
                ch--;
            }  
        }
        printf("\n");
    }
}