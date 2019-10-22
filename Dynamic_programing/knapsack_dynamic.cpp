#include<iostream>
using namespace std;
int main()
{
    int n, W,*w,*v,i,j;
    cout<<"enter the no. of objects:";
    cin>>n;
    w = new int[n+1];
    v = new int[n + 1];
    cout<<"Enter the weights of the object:"<<endl;
    w[0] = v[0] = 0;
    for(i=1;i<=n;i++)
    {
        cout<<"["<<i<<"]:";
        cin>>w[i];
    }

    cout<<"Enter the value of the object:"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"["<<i<<"]:";
        cin>>v[i];

    }

    cout<<"Enter the max. capacity of knapsack:";
    cin>>W;

    int V[n+1][W+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i == 0 || j == 0)
            {
                V[i][j] = 0;
            }
            else if(j < w[i])
            {
                V[i][j] = V[i-1][j];
            }
            else if(j >= w[i])
            {
                V[i][j] = max(V[i-1][j], (V[i-1][j-w[i]] + v[i]));
            }
        }
    }

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<V[i][j]<<'\t';
        }
        cout<<endl;
    }

    cout<<"maximum value of knapsack would be:"<<V[n][W];
    return 0;
}
