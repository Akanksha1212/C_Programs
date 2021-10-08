/*Function to left Rotate arr[] of size n by 1*/
void leftRotatebyOne(int arr[], int n);

/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n)
{
int i;
for (i = 0; i < d; i++)
	leftRotatebyOne(arr, n);
}

void leftRotatebyOne(int arr[], int n)
{
int i, temp;
temp = arr[0];
for (i = 0; i < n-1; i++)
	arr[i] = arr[i+1];
arr[i] = temp;
}

/* utility function to print an array */
void printArray(int arr[], int size)
{
int i;
for(i = 0; i < size; i++)
	printf("%d ", arr[i]);
}

/* Driver program to test above functions */
int main()
{
int arr[] = {1, 2, 3, 4, 5, 6, 7};
leftRotate(arr, 2, 7);
printArray(arr, 7);
getchar();
return 0;
}
