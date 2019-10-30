long dynamic_fibonacci (int n)
{
    //     n  = 1 2 3 4 5 6 7 8  9
    // fib(n) = 0 1 1 2 3 5 8 13 21
        
    int fib[n-1];
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i < n-1; i++)
    {
        fib[i] = fib[i-2] + fib[i-1];
    }

    return fib[n-2];
}
