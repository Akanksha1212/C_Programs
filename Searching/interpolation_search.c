// Interpolation Searvh
#include<stdio.h> 
 
//Return -1 if element not present
int interpolationSearch(int arr[], int n, int x) 
{ 
 
    int lo = 0, high = (n - 1); 
  
    while (lo <= high && x >= arr[lo] && x <= arr[high]) 
    { 
        if (lo == high){ 
            if (arr[lo] == x) return lo; 
            return -1; 
        } 

        int pos = lo + (((double)(high-lo) / 
              (arr[high]-arr[lo]))*(x - arr[lo])); 
  

        if (arr[pos] == x) 
            return pos; 
  
  
        if (arr[pos] < x) 
            lo = pos + 1; 
  
     
        else
            high = pos - 1; 
    } 
    return -1; 
} 
  
// Driver Code 
int main() 
{ 
    // Array of items on which search will 
    // be conducted. 
    int arr[] =  {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 
                  24, 33, 35, 42, 47}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    int x = 18; // Element to be searched 
    int index = interpolationSearch(arr, n, x); 
  
    // If element was found 
    if (index != -1) 
        printf("Element found at index %d", index); 
    else
        printf("Element not found."); 
    return 0; 
} 
