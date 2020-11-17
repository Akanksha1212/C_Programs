#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 20
void PUSH( int *, int *, int ); //FUNCION Diclaration
int POP( int *S, int *T);
void DISP( int *S, int T );
int main( void )
{
 int stack[ SIZE ], top= -1, n=1, i, v1, v2, res=0;
 char postfix[SIZE];
printf("Please enter a postfix expression: ");
scanf("%s",postfix);
 n = strlen(postfix);
 printf("YOU HAVE ENTERED = %s \t LEN=%d\n",postfix,n);
for( i=0; i<n; i++ )
 {
 if( isdigit(postfix[i]) )
 PUSH( stack, &top, postfix[i]-48);
 else
 {
 v1 = POP( stack, &top );
 v2 = POP( stack, &top );
 switch( postfix[i] )
 {
 case '*':
 res = v2 * v1;
 break;
 case '/':
 res = v2 / v1;
 break;
 case '+':
 res = v2 + v1;
 break;
 case '-':
 res = v2 - v1;
 break;
 case '^':
 res = pow(v2, v1);
 break;
 }
 PUSH( stack, &top, res);
 }
 DISP( stack, top);
 }
 printf("Reasult is = %d\n", POP( stack, &top ));
 return 0;
}
void PUSH( int *S, int *T, int val) //FUNCTION DEFINITION
{

if( *T == SIZE-1 )
 printf("!ERROR STACK OVERFLOW\n");
 else
 {
 ++(*T);
 S[*T] = val;
 }
}
int POP( int *S, int *T) //FUNCTION DEFINITION
{
 int val=0;//printf("ADDRESS stack = %p \t top=%p\n", S, T );
 if( *T == -1 )
 printf("!ERROR STACK UNDERFLOW\n");
 else
 {
 val = S[*T];
 --(*T);
 }
 return(val);
}
void DISP( int *S, int T )
{
 if( T == -1 )
 printf("!!!!Stack is empty!!!!!\n");
 else
 {
 while(T != -1)
 {
 printf("| %d |\n", S[T--]);
 }
 printf("----\n");
 }
}
