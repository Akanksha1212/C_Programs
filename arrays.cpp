#include<iostream>//in this code i am doing all the prorams given in array chapter
#include<iomanip>
using namespace std;
const int size=5;
/*int function(const float x[]){//passing array as constants
	for (int i =0;i<size;i++)
	cout<<endl<<x[i]*x[i];
}
*/
int main()
{ 
  /*  cout<<setw(10)<<setfill('*')<<"anmol";//stars being filled at left 
    float array[5];
    cout<<"\nenter the values of the array\n"
	;
	for(int i=0;i<size;i++)
	cin>>array[i];
	function(array);
	cout<<"\n lets see the change\n";
for(int i=0;i<size;i++)
cout<<array[i]<<endl;	
*/
cout<<"enter values for 2d array\n";
int a[size][size];
int j,i;
for(i=0;i<size;i++)
{
	for(j=0;j<size;j++)
	cin>>a[i][j];
}
for(i=0;i<size;i++)
{
	for(j=0;j<size;j++)
	   {
	   	if(i==j)
	   	a[i][j]=0;
	   	else if(i>j)
	   	a[i][j]=1;
	   	else a[i][j]=3;
	   }
}

for(i=0;i<size;i++)
{
	for(j=0;j<size;j++)
	cout<<a[i][j]<<" ";
	cout<<endl;
}
	return 0;
}

