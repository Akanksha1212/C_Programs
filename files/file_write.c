#include <stdio.h>
#include <stdlib.h>

int write_string_to_file(char* filename, char* text) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }
    int result = fprintf(fp, "%s", text);
    if (result < 0) {
        return -1;
    }
    fclose(fp);
}

int main() {
    char* filename = "test.txt";
    char* text = "My text";

    int result = write_string_to_file(filename, text);
    if (result < 0) {
        printf("An error occurred while writing the file.");
        return 1;
    }

    return 0;
}