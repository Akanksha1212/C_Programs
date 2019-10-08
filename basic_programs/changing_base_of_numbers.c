#include<stdio.h>
#include<math.h>
int main ()
{
	long long int c, a=0,n,x,y,m,k=0,r,d=0,l,len,start,end,temp;
	int z[100000];
	scanf("%lld %lld %lld",&n,&x,&y);

	while (n>0)
	{
	r=n%10;
	n=n/10;
	a=pow(x,k)*r + a;
	k++;
       	}
	
	
	if (y==10)
	printf("%lld",a);

	else
	{
	while (a>0)
	{ c = a%y;
	  a = a/y;
	  c=z[0];
	}
	len=sizeof(z)/sizeof(z[0]);
	end= len -1;
	while (start<end) {
		temp = z[end];
		z[end]=z[start];
		z[start]=temp;
		start++;end--;
        	}
	for (l=0; l<len;l++)
		printf("%d",z[l]);
	}
return 0;
}


		
		
		
							
	
