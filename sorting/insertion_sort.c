// C language implementation of Insertion sort 
#include <stdio.h> 
void swap(int *A, int *B) 
{ 
	int tmp = *A; 
	*A = *B; 
	*B = tmp; 
} 

void insertionSort(int arr[], int n) 
{ 
  int i, j; 
  for (i = 0; i < n; i++)	 
    for (j = i; j > 0; j--) { 
      if (arr[j] < arr[j-1]) 
        swap(&arr[j], &arr[j-1]); 
      else break;
    }
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int arr[] = {24, 22, 10, 48, 3, 15, 34}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	insertionSort(arr, n); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
