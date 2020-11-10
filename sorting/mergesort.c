#include <stdio.h> 
#include <stdlib.h> 
#include <cs50.h>
  
void merge(int arr[], int left, int middle, int right) 
{ 
    int i, j, k; 
    int n1 = middle - left + 1; 
    int n2 = right - middle; 
  
    int Left[n1], Right[n2]; 
  
    for (i = 0; i < n1; i++) 
        Left[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        Right[j] = arr[middle + 1 + j]; 
  

    i = 0; 
    j = 0; 
    k = left;
    while (i < n1 && j < n2) { 
        if (Left[i] <= Right[j]) { 
            arr[k] = Left[i]; 
            i++; 
        } 
        else { 
            arr[k] = Right[j]; 
            j++; 
        } 
        k++; 
    } 
  

    while (i < n1) { 
        arr[k] = Left[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = Right[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) { 

        int middle = left + (right - left) / 2; 
  

        mergeSort(arr, left, middle); 
        mergeSort(arr, middle + 1, right); 
  
        merge(arr, left, middle, right); 
    } 
} 
  

void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  

int main() 
{ 
    int arr[] = { 222456855, 1879791, 15468483, 52138654, 6894531, 756845213 }; //Enter your numbers  here
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
} 
