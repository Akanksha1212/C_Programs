#include<bits/stdc++.h>
using namespace std;

int ternarySearch(int low, int high, int *a, int target)
{
    int mid1 = low + (high - low) / 3;
    int mid2 = high - (high - low) / 3;

    if(high>=low)
    {
        if(target==a[mid1])
            return mid1;
        if(target==a[mid2])
            return mid2;

        if(key<a[mid1])
            return ternarySearch(low, mid1-1, a, target);
        else if(key>a[mid2])
            return ternarySearch(mid2+1, high, a, target);
        else
            return ternarySearch(mid1+1, mid2-1, a, target);
    }
    return -1;
}

int main()
{
    int i,n;
    cout<<"enter array size:";
    cin>>n;
    int a[n];
    cout<<"enter array:";
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);

        int k;
        cout<<"enter key";
        cin>>k;
        cout<<"found at position: "<<ternarySearch(0,n-1,a,k)<<"\n";
    return 0;
}
