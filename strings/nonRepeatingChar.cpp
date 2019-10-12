#include<iostream>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;


char nonRepeatingCharacter(string str){
  char v='0';
  for(int i=0;i<str.size();i++)
    {
        if(count(str.begin(),str.end(),str[i])==1)
        {
            v=str[i];
            break;
        }
    }
    if(v=='0')
        return str[0];
    else
        return v;

}
int main()
{
    string str;
    cin>>str;
    cout<<nonRepeatingCharacter(str);

}

