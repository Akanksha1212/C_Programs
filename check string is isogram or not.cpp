#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
map<char,int> mymap;
int main() {

	    string str;
	    //Isogram is a string in which no letter occurs more than once.
	    cout<<"Enter the string to check if it is isogram or not ";
	    cin>>str;
	    int i;
	    for(i=0;str[i];i++)
	    {
	        mymap[str[i]]++;
	    }
	    int flag=1;
	    map<char,int>::iterator it=mymap.begin();
	    while(it!=mymap.end())
	    {
	        if(it->second>1)
	        {
	            flag=0;
	            break;
	        }
	       	        ++it;
	    }

	    if(flag==0)
	    {
	        cout<<"The entered string is not isogram\n";
	    }
	    else
        {
            cout<<"The entered string is isogram\n";

        }
	   mymap.clear();
	getch();
	return 0;
}
