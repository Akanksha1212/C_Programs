// Program to print Sum of n numbers

#include"stdio.h"

int main(void){
	int n,i,sum=0;
	
	printf("Enter the Number upto you want Addition :\n");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		sum =sum+i;
	}
	printf("\n");
	printf("Sum of the numbers upto %d is %d",n,sum);
	
	return 0;
}
