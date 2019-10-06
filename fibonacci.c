#include<stdio.h>
long long int mod=1e9 + 7;
const int max =1e6 + 5;
long long int f[1000005];
long long int fib(long long int n)
{
	if(f[n] != -5) return f[n];
	if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
	{
		f[n]=(fib(n-1)+fib(n-2))%mod;
		return f[n];
	}

}
int main()
{
	long long int n;
	int t;
	scanf("%d",&t);
		for(int i=0;i<max;i++)
			f[i]=-5;
		while(t--)
	
	{
		scanf("%lld",&n);
		printf("%lld\n",fib(n));
		
	}
	return 0;
	
}

