#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n)
{
    if (n == 1)
        return;

    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1]) {
            int tmp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = tmp;
        }

    bubbleSort(arr, n - 1);
}

int main()
{
    int arr[10];
    //generate random numbers and fill array
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
