#include<stdio.h>
#include<stdbool.h>

/*
	Time Complexity : O(sqrt(N))
	Space Complexity : O(1)

*/

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n == 3) return true;
	if (n == 5) return true;
	if (n % 2 == 0) return false;
	if (n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

int main() {
	int n = 5;
	if (isPrime(n)) {
		printf("%d is Prime Number\n", n);
	} else {
		printf("%d is not a Prime Number\n", n);
	}
	return 0;
}