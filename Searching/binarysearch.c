#include<stdio.h>

/*
    Time Complexity : O(logN)
    Space Complexity : O(1)
*/

int binarySearch(int a[], int n, int target) { // function to find element
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] < target) { 
            low = mid + 1;
        } else if (a[mid] == target) {
            return mid;
        } else { // a[mid] > target
            high = mid - 1;
        }
    }
    return -1; // if target element not found in array
}

int main() {

    int n = 5, found = -1, target = 6;
    int a[] = {1, 2, 3, 4, 5}; // array needs to be sorted in ascending order
    
    found = binarySearch(a, n, target);

    if (found == -1) {
        printf("Element not present in array\n");
    } else {
        printf("Element found at index %d\n", found);
    }

    return 0;

}