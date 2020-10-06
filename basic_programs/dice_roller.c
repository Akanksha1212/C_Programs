#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll(int sides)
{

    clock_t seed;
    seed = clock();
    srand(seed);

    return (rand() % sides + 1);
}

int main()
{

    int sides = 1;

    printf("\n# # #  Dice Roller  # # #");

    do
    {

        printf("\n\nEnter the number of sides: (0 to exit)\n");
        scanf("%d", &sides);
        if (sides == 0)
            break;
        printf("You rolled %d", roll(sides));

    } while (sides != 0);

    return 0;
}