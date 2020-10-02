// Sum of the Digits in Given Numbers

#include"stdio.h"

int main(void){
	int n,r,sum=0,temp;
	
	printf("Sum of Digits in Given Numbers:\n");
	printf("Enter the Number: ");
	scanf("%d",&n);
	temp=n;
	while(n>0){
		
		r = n % 10;
		sum = sum + r;
		n = n / 10;
	}
	n=temp;
	printf("\n");
	printf("Addtion of the Digits of %d is %d",n,sum);
	
	return 0;	
}
