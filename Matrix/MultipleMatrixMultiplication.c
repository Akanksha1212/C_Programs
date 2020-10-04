#include <stdio.h>
#include <string.h>

void input(int matrix[][10], int row, int column) {

   printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         scanf("%d", &matrix[i][j]);
      }
   }
}


void multiply(int first[][10],int second[][10],int result[][10],int r1, int c1, int r2, int c2) {

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         result[i][j] = 0;
      }
   }

   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         for (int k = 0; k < c1; ++k) {
            result[i][j] += first[i][k] * second[k][j];
         }
      }
   }
}

void display(int result[][10], int row, int column) {

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         printf("%d  ", result[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

int main() {
   int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2;
      
   int nm;
   printf("Enter number of matrices you want to multiply: \n");
   scanf("%d",&nm);

   printf("Enter no. of rows and column for the first matrix: ");
   scanf("%d %d", &r1, &c1);
   input(first, r1, c1);

   while(--nm>0){
	   	printf("Enter no. of rows and column for the next matrix: ");
	   	scanf("%d %d", &r2, &c2);
		   	if (c1 != r2) {
		      printf("\nNo. of Columns of first matrix not equal to no. of rows of second matrix!!");
		      return 0;
		   	}
		input(second, r2, c2);
		multiply(first, second, result, r1, c1, r2, c2);
		r1=r1;
		c1=c2;
		memcpy(first, result, 100);
   }

   display(result, r1, c2);
   return 0;
}


/********************************************
Output:
Enter number of matrices you want to multiply: 
3
Enter no. of rows and column for the first matrix: 1 1

Enter elements: 
1
Enter no. of rows and column for the next matrix: 2 1 3

Enter elements: 
1 2 3
Enter no. of rows and column for the next matrix: 3 2

Enter elements: 
1 3 4
2 5 6

Output Matrix:
24  25  


Ouput:
Enter number of matrices you want to multiply: 
4
Enter no. of rows and column for the first matrix: 2 3

Enter elements: 
1 2
2 3  
3 4
Enter no. of rows and column for the next matrix: 3 2

Enter elements: 
4 5 6
2 3 4
Enter no. of rows and column for the next matrix: 1 2

No. of Columns of first matrix not equal to no. of rows of second matrix!!



********************************************/
