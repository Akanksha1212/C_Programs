/*
	Find the only odd occurring number in the array.
	Ex: [8,7,7,8,8]
	O/P: 8 (as it is 3 times in the array)

	Ex: [4,3,4,4,4,5,5]
	O/P: 3(as it is occurring 1 time which is odd number of times)
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Size of the array: ";	cin>>n;
	int arr[n];
	cout<<"Elements:\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int res=0;
	for(int i=0;i<n;i++){
		res^=arr[i];
	}

	cout<<"Odd occurring element is: "<<res<<endl;
	return 0;
}