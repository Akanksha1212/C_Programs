#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
int partition(int *arr,int low,int high){
  int i=low-1;
  int pivot=arr[high];
  for(int j=low;j<high;j++){
    if(arr[j]<pivot){
      i++;
      swap(&arr[j],&arr[i]);
    }
  }
  swap(&arr[i+1],&arr[high]);
  return (i+1);
}
void quickSort(int *arr,int low,int high){
  if(low<high){
    int part=partition(arr,low,high);
    quickSort(arr,low,part-1);
    quickSort(arr,part+1,high);
  }
}
void printArray(int *arr,int N){
  for(int i=0;i<N;i++){
    printf("%d   ",arr[i]);
  }
}
int main(){
  int N;
  printf("Enter the number of elements\n");
  scanf("%d",&N);
  int *arr=malloc(N*sizeof(*arr));
  printf("\nEnter the elements of array\n");
  for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  printf("\nOriginal Array\n");
  printArray(arr,N);
  printf("\n");
  quickSort(arr,0,N-1);
  printf("\n");
  printf("\nSorted Array\n");
  printArray(arr,N);
}
