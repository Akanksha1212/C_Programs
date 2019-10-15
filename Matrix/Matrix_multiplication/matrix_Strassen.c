#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

int r, c;

static double diff_in_second (struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return (diff.tv_sec + diff.tv_nsec / 1000000000.0);
}

void get_matrix (int **A, int **B)
{
    int i, j, k;
    for (i = 0; i < r; i++)
        for (j = 0; j < r; j++)
            k = scanf("%d", &A[i][j]);
    k = scanf("%d%d", &r, &r);
    for (i = 0; i < r; i++)
        for (j = 0; j < r; j++)
            k = scanf("%d", &B[i][j]);
    if (!k)
        printf("ERROR:input error.\n");
}

void display (int **A)
{
    int i, j;
    for (i = 0; i < r; i++, printf("\n"))
        for (j = 0; j < r; j++)
            printf("%5d ", A[i][j]);
}

void matrix_sub (int N, int **A, int **B, int **C)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void matrix_add (int N, int **A, int **B, int **C)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void matrix_mul_seq (int N, int **A, int **B, int **C)
{
    for (int i=0; i<N; i++)
			for (int j=0; j<N; j++)
				C[i][j]=0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                C[i][j] += A[i][k] * B[k][j]; 
}

void Strassen (int N, int **A, int **B, int **C)
{

    /* divide origin matrix into four pieces
            A11 | A12
            A21 | A22   
    */  
    
    if (N <= 16) {
        matrix_mul_seq(N, A, B, C);
		return;
	}
	int **M1, **M2, **M3, **M4, **M5, **M6, **M7;
	int **A11, **A12, **A21, **A22;
	int **B11, **B12, **B21, **B22;
	int **C11, **C12, **C21, **C22;
	int **AA, **BB;
	int i, j, size = N/2;

	/* initialize for array */
	A11 = (int **)malloc(size * sizeof(int *));A12 = (int **)malloc(size * sizeof(int *));A21 = (int **)malloc(size * sizeof(int *));A22 = (int **)malloc(size * sizeof(int *));
    B11 = (int **)malloc(size * sizeof(int *));B12 = (int **)malloc(size * sizeof(int *));B21 = (int **)malloc(size * sizeof(int *));B22 = (int **)malloc(size * sizeof(int *));
    C11 = (int **)malloc(size * sizeof(int *));C12 = (int **)malloc(size * sizeof(int *));C21 = (int **)malloc(size * sizeof(int *));C22 = (int **)malloc(size * sizeof(int *));
    M3 = (int **)malloc(size * sizeof(int *));M5 = (int **)malloc(size * sizeof(int *));M2 = (int **)malloc(size * sizeof(int *));M4 = (int **)malloc(size * sizeof(int *));
    M1 = (int **)malloc(size * sizeof(int *));M7 = (int **)malloc(size * sizeof(int *));M6 = (int **)malloc(size * sizeof(int *));
    AA = (int **)malloc(size * sizeof(int *));BB = (int **)malloc(size * sizeof(int *));
    for (i = 0; i < size; i++)
    {
        A11[i] = (int *)malloc(size * sizeof(int));A12[i] = (int *)malloc(size * sizeof(int));A21[i] = (int *)malloc(size * sizeof(int));A22[i] = (int *)malloc(size * sizeof(int));
        B11[i] = (int *)malloc(size * sizeof(int));B12[i] = (int *)malloc(size * sizeof(int));B21[i] = (int *)malloc(size * sizeof(int));B22[i] = (int *)malloc(size * sizeof(int));
        C11[i] = (int *)malloc(size * sizeof(int));C12[i] = (int *)malloc(size * sizeof(int));C21[i] = (int *)malloc(size * sizeof(int));C22[i] = (int *)malloc(size * sizeof(int));
        M3[i] = (int *)malloc(size * sizeof(int));M5[i] = (int *)malloc(size * sizeof(int));M2[i] = (int *)malloc(size * sizeof(int));M4[i] = (int *)malloc(size * sizeof(int));
        M1[i] = (int *)malloc(size * sizeof(int));M7[i] = (int *)malloc(size * sizeof(int));M6[i] = (int *)malloc(size * sizeof(int));
        AA[i] = (int *)malloc(size * sizeof(int));BB[i] = (int *)malloc(size * sizeof(int));
    }
	/* set array value */
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+size];
            A21[i][j] = A[i+size][j];
            A22[i][j] = A[i+size][j+size];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+size];
            B21[i][j] = B[i+size][j];
            B22[i][j] = B[i+size][j+size];
        }
    }
	/* M1 = (A11 + A22) (B11 + B22) */
	matrix_add(size,A11,A22,AA);
	matrix_add(size,B11,B22,BB);
	Strassen(size,AA,BB,M1);
	/* M2 = (A21 + A22)B11 */
	matrix_add(size,A21,A22,AA);
	Strassen(size,AA,B11,M2);
	/* M3 = A11(B12 − B22) */
	matrix_sub(size,B12,B22,AA);
	Strassen(size,A11,AA,M3);
	/* M4 = A22(B21 − B11) */
	matrix_sub(size,B21,B11,AA);
	Strassen(size,A22,AA,M4);
	/* M5 = (A11 + A12)B22 */
	matrix_add(size,A11,A12,AA);
	Strassen(size,AA,B22,M5);
	/* M6 = (A21 − A11)(B11 + B12) */
	matrix_sub(size,A21,A11,AA);
	matrix_add(size,B11,B12,BB);
	Strassen(size,AA,BB,M6);
	/* M7 = (A12 − A22)(B21 + B22) */
	matrix_sub(size,A12,A22,AA);
	matrix_add(size,B21,B22,BB);
	Strassen(size,AA,BB,M7);
	/* C11 = M1 + M4 − M5 + M7 */
	matrix_add(size,M1,M4,AA);
	matrix_sub(size,M7,M5,BB);
	matrix_add(size,AA,BB,C11);
	/* C12 = M3 + M5 */
	matrix_add(size,M3,M5,C12);
	/* C21 = M2 + M4 */
	matrix_add(size,M2,M4,C21);
	/* C22 = M1 − M2 + M3 + M6 */
	matrix_sub(size,M1,M2,AA);
	matrix_add(size,M3,M6,BB);
	matrix_add(size,AA,BB,C22);

	// save the result
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + size] = C12[i][j];
            C[i + size][j] = C21[i][j];
            C[i + size][j + size] = C22[i][j];
        }
    }

	for (i = 0; i < size; i++)
    {
        free(A11[i]);free(A12[i]);free(A21[i]);free(A22[i]);
        free(B11[i]);free(B12[i]);free(B21[i]);free(B22[i]);
        free(C11[i]);free(C12[i]);free(C21[i]);free(C22[i]);
        free(AA[i]);free(BB[i]);
        free(M3[i]);free(M5[i]);free(M2[i]);free(M4[i]);free(M1[i]);free(M7[i]);free(M6[i]);
    }
    free(A11);free(A12);free(A21);free(A22);
    free(B11);free(B12);free(B21);free(B22);
    free(C11);free(C12);free(C21);free(C22);
    free(AA);free(BB);
    free(M3);free(M5);free(M2);free(M4);free(M1);free(M7);free(M6);
        
}



int main()
{
    int i, j;
    int **A, **B, **C;
    struct timespec start, end;
    //pthread_t thread[thread_num];
    i =scanf("%d%d", &r, &c);
    /* declare 2D array of matrix */
    A = (int **)malloc(r * sizeof(int *));
    B = (int **)malloc(r * sizeof(int *));
    C = (int **)malloc(r * sizeof(int *));
    for (i = 0; i<r; i++)
    {
        A[i] = (int *)malloc(r*sizeof(int));
        B[i] = (int *)malloc(r*sizeof(int));
        C[i] = (int *)malloc(r*sizeof(int));
    }

    /* input matrix */
    get_matrix(A, B);
    /* initialize */
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            C[i][j] = 0;

    // Strassen mul
    clock_gettime(CLOCK_REALTIME, &start);
    Strassen (r, A, B, C);
    clock_gettime(CLOCK_REALTIME, &end);

    //display (C);

    printf("execution time of Strassen : %lf sec\n", diff_in_second(start, end));
    
    return 0;
}

