#include <stdio.h>

void quickSort(int numbers[], int left, int right) {
    int pivot, left_hold, right_hold;

    left_hold = left;
    right_hold = right;
    pivot = numbers[left];

    while (left < right) {
        while ((numbers[right] >= pivot) && (left < right)) {
            right--;
        }
        if (left != right) {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right)) {
            left++;
        }
        if (left != right) {
            numbers[right] = numbers[left];
            right--;
        }
    }

    numbers[left] = pivot;
    pivot = left;
    left = left_hold;
    right = right_hold;

    if (left < pivot) {
        quickSort(numbers, left, pivot - 1);
    }
    if (right > pivot) {
        quickSort(numbers, pivot + 1, right);
    }
}

void prep(int numbers[], int arr_size) {
    quickSort(numbers, 0, arr_size - 1);
}

void printSortedArr(int numbers[], int arr_size) {
    int n;
    for (n = 0; n < arr_size; n++)
    {
        printf("%d ", numbers[n]);
    }
}

int main(void) {
    int numbers[5], i;
    for (i = 0; i <= 5; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (i = 0; i <= 5; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("<--before\n");
    prep(numbers, 5);
    printSortedArr(numbers, 5);
    printf("<--after\n");

    return 0;
}
