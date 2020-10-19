#include <stdlib.h> 
#include <time.h> 
#include <unistd.h> 
  
#define RefRate 30000 
#define randomness 5
  
void clrscr() 
{ 
    system("@cls||clear"); 
} 
  

void printRandLeaf() 
{ 
    char leaftypes[5] = { '.', '*', '+', 'o', 'O' }; 
    int temp = rand() % randomness; 
  
    if (temp == 1) 
        printf("%c ", leaftypes[rand() % 5]); 
    else
        printf("%c ", leaftypes[1]); 
} 
  
void triangle(int f, int n, int toth) 
{ 
    int i, j, k = 2 * toth - 2; 
  
    for (i = 0; i < f - 1; i++) 
        k--; 
  
    for (i = f - 1; i < n; i++) { 
  
        for (j = 0; j < k; j++) 
            printf(" "); 
  
        k = k - 1; 
  
        for (j = 0; j <= i; j++) 
            printRandLeaf(); 
  
        printf("\n"); 
    } 
} 
  

void printTree(int h) 
{ 
    int start = 1, stop = 0, diff = 3; 
    while (stop < h + 1) { 
        stop = start + diff; 
        triangle(start, stop, h); 
        diff++; 
        start = stop - 2; 
    } 
} 
  
void printLog(int n) 
{ 
    int i, j, k = 2 * n - 4; 
  
    for (i = 1; i <= 6; i++) { 
  
        // space handler 
        for (j = 0; j < k; j++) 
            printf(" "); 
  
        for (j = 1; j <= 6; j++) 
            printf("#"); 
  
        printf("\n"); 
    } 
} 
  

int main() 
{ 
    srand(time(NULL)); 
    int ht = 6; 
  
    printf("\n*********MERRY XMAS*********\n\n"); 
  
    // refresh loop 
    while (1) { 
        clrscr(); 
        printTree(ht); 
  
        printLog(ht); 
        usleep(RefRate); 
    } 
  
    return 0; 
} 
