/*recursive implementation of length of Longest common subsequence problem*/

#include<stdio.h>
#include<string.h> 
/* function to get max of 2 integers */  
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
int lcs( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
     return 0; 
   if (X[m-1] == Y[n-1]) 
     return 1 + lcs(X, Y, m-1, n-1); 
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 

int main() 
{ 
  int n1,n2;// lengths of two sequences
  printf("Enter length of first sequence-");
  scanf("%d",&n1);
  printf("\nEnter length of second sequence-");
  scanf("%d",&n2);
  char X[n1],Y[n2];
  printf("\nEnter first sequence-");
  scanf("%s", &X);  //scanning the whole string, including the white spaces
  printf("\nEnter second sequence-");
  scanf("%s", &Y);  //scanning the whole string, including the white spaces
        
  printf("\nLength of LCS is %d", lcs( X, Y, n1, n2 ) ); 
  
  return 0; 
} 
