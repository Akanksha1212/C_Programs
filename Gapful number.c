#include <stdio.h>

  //  A GAPFUL NUMBER is a number of at least 3       digits that is divisible by the number formed by the first and last digit of the original number.
   //this is my first coading chellange answer
   
    //enter a number to check whether it is gapful number or not 
    
int main() {
    int n,number,l,q;
    scanf("%d",&n);
    number=n;
    while(n>=10){
     n=n/10;}
    q=number%10;
    l=10*n + q;
     if (number%l==0)
    printf("    %d is a gapful number it is\n \t   devisible by %d. ",number,l);
    else 
   printf ("    %d is not a gapful number",number);
 }   
//this is the simplest one
