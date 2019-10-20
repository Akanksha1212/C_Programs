// Run: ./caesar (shiftAmount)

#include <stdio.h>
#include <stdlib.h>


int characterShift(char c, int offset);

int modulo(int x, int N);


int main(int argc, char *argv[]) {
    char c;

    // Repeat until we get an EOF
    while ((c = getchar()) != EOF) {
        putchar(characterShift(c, atoi(argv[1])));
    }
    return 0;
}


int characterShift(char c, int offset) {
    // If the char `c` is a lowercase letter, then cycle between 'a' and 'z'
    if ('a' <= c && c <= 'z') return 'a' + modulo(c - 'a' + offset, 26);

    // If the char `c` is a lowercase letter, then cycle between 'A' and 'Z'
    if ('A' <= c && c <= 'Z') return 'A' + modulo(c - 'A' + offset, 26);

    // If the char `c` is not a letter, then return it as-is
    return c;
}


int modulo(int x, int N) {
    // This function returns a positive modulo

    // https://stackoverflow.com/a/42131603
    // -5 % 7 == -5 in C
    // -5 % 7 == 2 in Python
    return (x % N + N) % N;
}
