/*input
5
5 1 2 6 3
*/

// Time complexity O(N2)
// Space complexity O(1)
// Inplace sorting
// stable sorting
// good when array is big and most of the elements are already sorted

#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *arr, int n){

	for(int i = 0; i < n; i++){
		int key = arr[i];
		int j = i - 1;
		while(j >=0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}

}  

int main(){

	int n;
	scanf("%d", &n);
	int *a = (int *) malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	insertionSort(a, n);
	for(int i = 0; i < n; i++){
		printf("%d ", *(a + i));
	}
	printf("\n");

	return 0;
}