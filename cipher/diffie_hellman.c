#include <stdio.h>

unsigned long long int llPow(unsigned long long int a, unsigned long long int p) {
    unsigned long long int res = 1;
    for(unsigned long long int i = 0; i < p; i++) {
        res *= a;
    }

    return res;
}

int main() {

    unsigned long long int a, b, A, B, g, p, SA, SB;

    a = 19881104;
    b = 54296177;
    p = llPow(2, 56) - 46;
    g = 3;

    A = llPow(g, a) % p;
    B = llPow(g, b) % p;

    // choose a prime for p
    printf("A: %llu, B: %llu\n", A, B);

    SA = llPow(B, a) % p;
    SB = llPow(A, b) % p;

    printf("SA: %llu, SB: %llu\n", SA, SB);

    return 0;
}