#include<iostream>
#include<fstream>
using namespace std;
int main()
{   char ch;
	ifstream f1;
    f1.open("file2.txt");
    if(!f1)
    {
    	cout<<"error opening file";
    	return 0;
	}
	cout<<"Enter the text for copying into file\n";
	while(cin.get(ch))
	{
	f1.put(ch);	
    }
   f1.close();
    return 0;
    
}

