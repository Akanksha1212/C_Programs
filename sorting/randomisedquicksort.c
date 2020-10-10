#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int a[], int low, int high)
{
    srand(time(0));
    int pivot=low+rand()%(high-low+1);
    swap(&a[low], &a[pivot]);
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=a[pivot]&&i<high)
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
            swap(&a[i], &a[j]);   
    }
    swap(&a[pivot], &a[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low<high)
    {
        int pi=partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main()
{
    int i,num;
    printf("-------------------------------------------------------------\n");
    printf("Implementing Quicksort while selecting pivot element randomly\n");
    printf("-------------------------------------------------------------\n");
    printf("Enter number of elements: ");
    scanf("%d", &num);
    int arr[num];
    printf("Enter numbers: \n");
    for(i=0; i<num; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, num-1);
    printf("The sorted array is: \n");
    for (i=0; i<num; i++)
        printf("%d ", arr[i]);
    return 0;
}