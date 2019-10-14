#include <stdio.h>
#include <stdlib.h>

int prime(int n){
    int i,f=0;
    for(i=2;i<n;i++){
        if ((n % i) == 0)
            f=1;
    }
    return f;
}


int main() {

    int a,b,i;
    printf("Enter number for Interval start :");
    scanf("%d" , &a);
    printf("Enter number for Interval end :");
    scanf("%d" , &b);

    for (i=a;i<=b;i++){         //Considering a and b inclusive in the interval.
        if (prime(i)== 0)
            printf("%d\n" , i);
    }

    return 0;
}
