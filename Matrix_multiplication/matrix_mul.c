#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define thread_num 4

int r, c;
int **A, **B, **C;

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

void get_matrix ()
{
    int i, j, k;
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            k = scanf("%d", &A[i][j]);
    k = scanf("%d%d", &c, &r);
    for (i = 0; i < c; i++)
        for (j = 0; j < r; j++)
            k = scanf("%d", &B[i][j]);
    if (!k)
        printf("ERROR:input error\n");
}

void display (int **A)
{
    int i, j;
    for (i = 0; i < r; i++, printf("\n"))
        for (j = 0; j < c; j++)
            printf("%5d ", A[i][j]);
}

void *matrix_mul_thread (void *rank_arg)
{
    long rank = (long)rank_arg;
    for (int i = rank * r / thread_num; i < (rank+1) * r / thread_num; i++)
        for (int j = 0; j < c; j++)
            for (int k = 0; k < r; k++)
                C[i][j] += A[i][k] * B[k][j]; 
    //pthread_exit(0);
    return NULL;
}

int main()
{
    int i, j;
    struct timespec start, end;
    pthread_t thread[thread_num];
    i = scanf("%d%d", &r, &c);
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
    get_matrix();
    /* initialize */
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            C[i][j] = 0;
          
    /* traditional mul with pthread */
    clock_gettime(CLOCK_REALTIME, &start);
    for (long rank = 0; rank < thread_num; rank++)
        pthread_create(&thread[rank], NULL, matrix_mul_thread, (void *)rank);
    for (int rank = 0; rank < thread_num; rank++)
        pthread_join(thread[rank], NULL);
    clock_gettime(CLOCK_REALTIME, &end);

    //display (C);
    
    printf("execution time of pthread :  %lf sec\n", diff_in_second(start, end));
    
    return 0;
}

