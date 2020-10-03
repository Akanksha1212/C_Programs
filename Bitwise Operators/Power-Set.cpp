/*
	Generate power set by taking characters in the string as elements
	I/P: abc
	O/P: "","a","b","c","ab","ac","bc","abc"
*/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main(){
	string str;
	cout<<"String: ";
	cin>>str;
	
	int p = pow(2,str.length());
	
	for(int i=0;i<p;i++){
		int num = i,j=0;
		string res="";
		while(num!=0){
			if((num & 1)){
				res+=str[j];
			}
			num>>=1;
			
			j++;
		}
		cout<<"\""<<res<<"\""<<"\t";
	}
	cout<<endl;
	return 0;
}