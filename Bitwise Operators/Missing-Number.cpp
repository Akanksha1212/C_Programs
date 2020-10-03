/*
	An array of N numbers has values from 1 to N+1 with each number appearing exactly once 
	and one number is missing. Find the missing number.
	Ex:
	I/P: N = 3
		 arr= [1,4,3]
	O/P: 2
*/

#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"N:: ";
	cin>>n;

	int arr[n];
	cout<<"Elements 1-(N+1)::\n";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// XOR of all the elements present in the array
	// XOR of all the possible numbers between 1 to N+1
	// On doing XOR operation between results of above two operations, we will get missing number.

	int xorElements=0;
	for(int i=0;i<n;i++){
		xorElements ^= arr[i];
	}

	int xorNumbers=0;
	for(int i=1;i<=n+1;i++){
		xorNumbers^=i;
	}

	cout<<"Missing number:: "<<(xorNumbers^xorElements)<<endl;

	return 0;
}