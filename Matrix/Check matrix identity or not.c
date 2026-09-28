#include <stdio.h>

#define MAX 50 // Define a clear maximum size for the matrix

int main() {    
    int a[MAX][MAX]; 
    int i, j, n, flag = 1;

    printf("Enter order of the matrix: ");    
    scanf("%d", &n);    

    // Boundary check to prevent array overflow
    if (n > MAX || n <= 0) {
        printf("Invalid order. Please enter a number between 1 and %d.\n", MAX);
        return 1;
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++) {        
        for (j = 0; j < n; j++) {            
            scanf("%d", &a[i][j]);        
        }    
    }    

    // Checking matrix
    for (i = 0; i < n && flag; i++) {        
        for (j = 0; j < n && flag; j++) {            
            if (i == j) {                
                // check for diagonal elements                
                if (a[i][j] != 1)                    
                    flag = 0;            
            } else { 
                // check for non-diagonal elements                
                if (a[i][j] != 0)                    
                    flag = 0;            
            }        
        }    
    }    

    // Printing matrix for user verification
    printf("\nEntered matrix:\n");
    // Removed "&& flag" from this loop so it always prints the matrix
    for (i = 0; i < n; i++) {        
        for (j = 0; j < n; j++) {            
            printf("%5d", a[i][j]);        
        }        
        printf("\n");    
    }    

    // Result
    if (flag)        
        printf("\n===== Identity Matrix =====\n");    
    else        
        printf("\n===== Not an Identity Matrix =====\n");
        
    return 0;
}
