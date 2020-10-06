#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char str[101];
    cin>>n;
    cin>>str;

    int mark=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u'  ||str[i]=='y')
        {
            if(mark==1)
            {
                str[i]='X';
            }
            else
            {
                mark = 1;
            }
        }
        else
        {
            mark=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(str[i]!='X')
        {
            cout<<str[i];
        }
    }
    cout<<endl;
}