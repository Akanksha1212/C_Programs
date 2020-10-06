// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <stdio.h>

void SieveOfEratosthenes(int n) 
{ 
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	int prime[n+1]; 
	memset(prime, 0, sizeof(prime)); 

	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == 0) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = 1; 
		} 
	} 

	// Print all prime numbers 
	for (int p=2; p<=n; p++) 
	if (prime[p]==0) 
		printf("%d",p) ; 
} 

// Driver Program to test above function 
int main() 
{ 
    printf("Enter the number till which you have to find the prime number :");
    int n;
    scanf("%d",&n);
     
	printf( "Following are the prime numbers smaller than or equal to %d " , n ); 
	SieveOfEratosthenes(n); 
	return 0; 
} 
