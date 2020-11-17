#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
vector<char> v;
int main() {
	string s;
	cout<<"Enter the string in which you want to remove  consonants: ";
	     cin>>s;
	    int i;
	    for(i=0;s[i];i++)
	    {
	        if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='u'||s[i]=='U')
	        v.push_back(s[i]);
	    }
        string newstr="";
	    if(v.empty())
	    {newstr="";}
	    else
	    {
	        vector<char>::iterator it;
	        for(it=v.begin();it!=v.end();it++)
	        newstr+=*it;
	    }
	    if(newstr=="")
            cout<<"No vowels are present in this string";
        else
	        cout<<newstr;
	    v.clear();
	getch();
	return 0;
}
