#include<iostream>
#include<conio.h>
using namespace std;

int main() {

	    int i,x,N;
	    cout<<"Enter the number of elements in the array ";
	    cin>>N;
	    int arr[N];
	    cout<<"Enter elements ";
	    for(i=0;i<N;i++)
	    cin>>arr[i];
	    cout<<"Enter the element that you want to search in the array ";
	    cin>>x;
	    int flag=0;
	    for(i=0;i<N;i++)
	    {
	        if(arr[i]==x)
	        {
	            cout<<"Yeah "<<x<<" is present in the array\n";
	            flag=1;
	            break;
	        }
	    }
	    if(flag==0)
	    cout<<"Oops! "<<x<<" is not present in the array\n";

	    getch();
	return 0;
}
