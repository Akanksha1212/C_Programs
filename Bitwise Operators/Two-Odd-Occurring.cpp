/*
	Find two odd occurring numbers in the array.
	Ex: [3,4,3,4,5,4,4,6,7,7]
	O/P: 5 & 6 (1 time)
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Size of array: ";
	cin>>n;

	int arr[n];
	cout<<"Elements of array:\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// XOR of all elements of array
	// we will get XOR of two odd occuring elements

	// Get right most set bit number and divide elements of array into two categories
	// 1) Elements having that bit position set
	// 2) all other elements

	// XOR operations on each category gives both required elements


	int xorArray = 0;
	for(int i=0;i<n;i++){
		xorArray^=arr[i];
	}

	int rightSetNum = xorArray & ~(xorArray-1); // gives num with right most bit set at the exact pos as xorArray

	int res1=0,res2=0;
	for(int i=0;i<n;i++){
		if((arr[i] & rightSetNum) != 0) {
			res1^=arr[i];
		} else {
			res2^=arr[i];
		}
	}

	cout<<"Odd occurring elements are:: "<<res1<<" & "<<res2<<endl;

	return 0;
}