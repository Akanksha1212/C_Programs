// Program to swap the values of two variables without using a third variable

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter the value of first variable.");
    scanf("%d", a);

    printf("Enter the value of second variable.");
    scanf("%d", b);

    printf("Value before swapping- a: %d, b: %d", a, b);

    a = a+b;
    b = a-b;
    a = a-b;

    printf("Value after swapping- a: %d, b: %d", a, b);

    return 0;
}