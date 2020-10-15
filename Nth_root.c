#include <stdio.h>

//Power calcuate 
double pow(double x, int n) {
    double xn = 1;
    for(int i=0;i<n;i++) {
        xn *= x;
    }
    return xn;
}

// x ^ n - k
double fx(double x, int n, double k) {
    return pow(x,n) - k;
}

// n* x ^ n-1
double _fx(double x, int n) {
    return n*pow(x,n-1);
}

// next = curr - fx() / _fx()
double next(double curr, int n, double k) {
    return curr - fx(curr, n, k) / _fx(curr, n);
}

// apprx root for starting
double apprx(int n, double k) {
    double gt = 0, p = 0;
    while(gt < k) {
        gt = pow(++p, n);
    }
    return p - 0.5;
}

double abs(double diff) {
    return diff>0?diff:-diff;
}

int precision(double k, double _x, int n) {
    return abs(k-pow(_x,n)) < 0.0001;
}

double nThRoot(double k, int n) {
    double _x = apprx(n, k);
    while(!precision(k, _x, n)) {
        _x = next(_x, n, k);
    }
    return _x;
}

int main() {
    int n = 2;
    double k = 50;
    double x = nThRoot(k,n);
    printf("%d root of %lf : %lf\n",n,k,x);
    printf("%lf ^ %d = %lf", x,n, pow(x,n));
    return 0;
}
