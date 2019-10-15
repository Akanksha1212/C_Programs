#include <stdio.h>
float exponential(int n,float x);
void main() {
	int op, n;
	float x;
	printf("Enter n value : ");
	scanf("%d", &n);
	printf("Enter x value : ");
	scanf("%f", &x);
	x = (x * 3.14) / 180;
	printf("Exponential result = %f\n", exponential(n, x));
}


float exponential(int n,float x){
	float s=1,p;
	p=x;int j=1;
	for(int i=1;i<=n;i++)
{s+=p/(j*i);
	p=p*x;
	j=j*i;
}
return s;

}
