#include<stdio.h>

/*
    Time Complexity : O(logN)
    Space Complexity : O(1)
*/

int binarySearch(int a[], int low,int high, int target) { // function to find element
    if(low==high)
    {
        if(a[low]!=target)
        return -1;// if target element not found in array
        return low;
    }
    int mid=(low+high)/2;
    if(a[mid]<target)
    return binarySearch(a,mid+1,high,target);
    return binarySearch(a,low,mid,target);
}

int main() {

    int n = 5, found = -1, target = 6;
    int a[] = {1, 2, 3, 4, 5}; // array needs to be sorted in ascending order
    
    found = binarySearch(a, 0, n-1, target);

    if (found == -1) {
        printf("Element not present in array\n");
    } else {
        printf("Element found at index %d\n", found);
    }

    return 0;

}