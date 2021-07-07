#include <stdio.h>

//  source https://www.geeksforgeeks.org/program-to-find-lcm-of-two-numbers/

// Greatest common divisor
int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return (a*b) / gcd(a, b);
}

int main(void) {
    int a, b;
    printf("Insert two numbers separated with space:\n");
    scanf("%d %d", &a, &b);
    int lcmResult = lcm(a,b);
    printf("The lowest common multiplier of %d and %d is: %d\n", a, b, lcmResult);

}