#include <stdio.h>

enum DataType { INTEGER, FLOATING };

typedef struct {
    enum DataType type;
    union {
        int integer;
        float floating;
    };
} Data;

int main() {
    Data data;

    if (data.type == INTEGER) {
        printf("%d\n", data.integer);
    } else {
        printf("%f\n", data.floating);
    }
}
