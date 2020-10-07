#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a,b,ans=0;
		cin>>a>>b;
		bitset<8> A(a);
    	bitset<8> B(b);  
		if(A == B) 
		{
			cout<<ans<<endl;
		}
		else
		{
		if(B.to_ulong()%2==0)
		{
    	while (true) 
    	{
				A = A.to_ulong() + 1;
				ans++;
				if(A.count() == B.count())
    			{
    				cout<<ans<<endl;
					break;
				}
		}
		}
		else
		{
			while (true) 
    	{
				A = A.to_ulong() + 1;
				ans++;
				if(A.count() == B.count())
    			{
    				cout<<ans-1<<endl;
					break;
				}
		}
		
		}
		}
	}
}
