//Program to check if a number is a palindrome
#include<stdio.h>

int reverse(int n){
    int reverse,r;
    reverse=0;
    while(n!=0){    
        r=n%10;    
        reverse=reverse*10+r;    
        n/=10;    
    } 
    return reverse;
}

int main(){
    int num,rev;
    printf("Enter the number: ");
    scanf("%d",&num);
    rev= reverse(num);
    if(num==rev) printf("The number is a palindrome\n");
    else    printf("The number is not a palindrome\n");
    return 0;
}
