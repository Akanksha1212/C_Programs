#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int

void eulerSeive(ll n)
{
    ll a[n+2];
    for(ll i=0;i<=n+1;i++)
    {
        a[i]=i;
    }
    for(ll i=2;i<=n;i++)
    {
        if(a[i]==i)
        {
            a[i]=i-1;
            for(ll j=2*i;j<=n;j+=i)
            {
                a[j]=(a[j]*(i-1))/i;
            }
        }
        else
        {
            continue;
        }
    }
    for(ll i=1;i<=n;i++)
    cout<<"EULER TOTIENT PHI VALUE FOR "<<i<<" IS "<<a[i]<<endl;
    cout<<endl;
}
int main()
{
	ll t;
	cin>>t;
	eulerSeive(t);
	return 0;
}
