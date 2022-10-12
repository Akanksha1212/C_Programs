#include <stdio.h>
int m = 1000000007;
long long int determinant(int n, long long int arr[n][n])
{
    if (n == 1)
    {
        return arr[0][0];
    }
    if (n == 2)
    {
        return ((((arr[0][0])) * (arr[1][1])) - (((arr[1][0])) * (arr[0][1]))) % m;
    }
    long long int sum = 0;
    long long int arrsmall[n - 1][n - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k < i)
                {
                    arrsmall[j - 1][k] = arr[j][k];
                }
                else if (k > i)
                {
                    arrsmall[j - 1][k - 1] = arr[j][k];
                }
            }
        }
        if (i % 2 == 0)
        {
            sum = ((sum) + ((arr[0][i]) * (determinant(n - 1, arrsmall)))) % m;
        }
        else
        {
            sum = ((sum) - ((arr[0][i]) * (determinant(n - 1, arrsmall)))) % m;
        }
    }
    return sum % m;
}
int main()
{
    int n;
    scanf("%d", &n);
    double arr[n][n], arr3[n][n];
    double arr1[n][n];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &arr[i][j]);
            arr3[n - i - 1][j] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        long long int arr2[i + 1][i + 1];
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                arr2[j][k] = arr3[j][k];
            }
        }
        long long int v = determinant((i + 1), arr2);
        v = (v % m + m) % m;
        if (v == 0)
        {
            printf("No LU decomposition\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr1[i][j] = 0;
            if (i + j == n - 1)
            {
                arr1[i][j] = 1;
            }
        }
    }
    int i, j, b, p = n - 1;
    int h = n - 1;
    for (b = 0; b < n - 1; b++)
    {
        for (i = 0; i < p; i++)
        {
            double x = arr[i][b] / arr[h][b];
            arr1[i][b] = x;
            for (j = 0; j < n; j++)
            {
                arr[i][j] -= arr[h][j] * x;
            }
        }
        h--;
        p--;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.5lf ", (arr1[i][j]));
        }
        printf("\n");
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.5lf ", (arr[i][j]));
        }
        printf("\n");
    }
    return 0;
}
