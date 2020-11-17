#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 5
struct QUEUE
{
 int Head;
int Tail;
int Count;
int Queue[SIZE];
int Prio[SIZE];
};
typedef struct QUEUE QU;
//QU Q;
void INSERT( QU *x );
void DISPLAY( QU *x );
void DELETE( QU *x );
void INSTSORT( QU *x );
int main( void )
{
 QU Q;
 Q.Head=0;
 Q.Tail=0;
 Q.Count=0;

int n=1;
while(n)
 {
 printf("INSER press 1\n");
printf("DELETE press 2\n");
printf("DISPLAY pree 3\n");
printf("EXIT press 0\n");
scanf("%d", &n);
 switch(n)
 {
 case 1: INSERT( &Q );
 INSTSORT( &Q );
DISPLAY( &Q );//Function call break;
 case 2: DELETE( &Q );
 DISPLAY( &Q );
 break;
 case 3: DISPLAY( &Q );
 }
 }
 return 0;
}
void INSERT( QU *x )
{
 int val, P;
if ( x->Count == SIZE )
 printf("QUEUE is FULL!!!\n");
 else
 {
 printf("Please enter a value:");
scanf("%d", &val);
printf(" Please enter the priority of your data: ");
scanf("%d", &P);
 x->Queue[x->Tail] = val;
 x->Prio[x->Tail] = P;
 x->Tail = (x->Tail + 1)%SIZE;
 (x->Count)++;
 }
}
void INSTSORT( QU *x )
{
 int T, TP, H;
int tempVAL, tempPrio;
if(x->Count == 1)
 return;

if( x->Tail == 0 )
 T = SIZE-1;
 else
 T = (x->Tail)-1;
 
 if( T == 0 )
 TP = SIZE-1;
 else
 TP = T-1;
 H = x->Head;
 printf("T=%d, TP=%d \n",T,TP);//test print
 while( T != H )
 {
 printf("T=%d, TP=%d \n",T,TP);//test print
 if( x->Prio[T] > x->Prio[TP])
 {
 tempVAL = x->Queue[TP];
 tempPrio = x->Prio[TP];
 x->Queue[TP] = x->Queue[T];
 x->Prio[TP] = x->Prio[T];
 x->Queue[T] = tempVAL;
 x->Prio[T] = tempPrio;
 }
 else
 return;
 T = TP;
 if( T == 0 )
 TP = SIZE-1;
 else
 TP = T-1;
 }
 }
void DELETE( QU *x )
{

if ( x->Count == 0 )
 printf("QUEUE is EMPTY!!!\n");
 else
 {
 printf("DETETED = %d \n", x->Queue[x->Head]);
 x->Head = (x->Head + 1)%SIZE;
 (x->Count)--;
 }
}
void DISPLAY( QU *x )
{
 int i,j;
if ( x->Count == 0)
 printf("QUEUE is EMPTY!!\n");
 else
 {
 for( i=x->Head, j=x->Count; j>0; i=(i+1)%SIZE,j-- )
 printf("| V=%d P=%d |", x->Queue[i],x->Prio[i]);
 printf("\n");
 }
}
