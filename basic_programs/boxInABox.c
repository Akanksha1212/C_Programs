#include <stdio.h>

int main(void) {
    int box;
    printf("How many boxes: ");
    scanf("%d", &box);

    int dim = (4 * box) - 1;
    int row = 0;
    while (row < dim) {
        int col = 0;
        while (col < dim) {
            if (row % 2 == 0 && row < dim / 2 && col >= row && col < dim - row) {
                printf("#");
            } else if (row % 2 == 0 && row > dim / 2 && col <= row && col >= dim - row) {
                printf("#");
            } else if (col % 2 == 0 && col < dim / 2 && row >= col && col < dim - row) {
                printf("#");
            } else if (col % 2 == 0 && col > dim / 2 && row <= col && col >= dim - row) {
                printf("#");
            } else {
                printf(" ");
            }
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}