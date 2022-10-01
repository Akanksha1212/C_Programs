#include <stdio.h>
#include <math.h>

void driver();
int min(int, int);
int jumpSearch(int[], int, int);

int jumpSearch(int arr[], int x, int n)
{
	int jump = sqrt(n); // jump is the jump size

	int prev = 0; // find the element if present
	while (arr[min(jump, n) - 1] < x)
	{
		prev = jump;
		jump += sqrt(n);
		if (prev >= n)
			return -1;
	}

	while (arr[prev] < x) // linearly search in a block with start index prev
	{
		prev++;

		if (prev == min(jump, n)) // next block or end of array, element not found
			return -1;
	}

	if (arr[prev] == x) // element found
		return prev;

	return -1;
}

int min(int a, int b)
{
	return (b > a) ? a : b;
}

void driver()
{
	int n;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int key;
	printf("Enter the element to be searched: ");
	scanf("%d", &key);

	int index = jumpSearch(arr, key, n);

	(index >= 0) ? printf("Element found at index %d\n", index) : printf("Element not found\n");
	return;
}

int main()
{
	driver();
	return 0;
}
