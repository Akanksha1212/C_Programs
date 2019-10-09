#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int n;
    cout<<"Enter the number till which we have to find the prime numbers :"<<endl;
    cin>>n;

    vector<int> v(n+1,0);

    for(int i=2;i*i<n;i++)
    {
      if(v[i]==0)
      {
          for(int j=i+i;j<=n;j=j+i)
          {
                v[j]=1;
          }
      }  
    }

    cout<<"The prime numbers till value " <<n <<" are :"<<endl;
    for(int i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
            cout<<i<<" ";
        }
    }



    return 0;
}
