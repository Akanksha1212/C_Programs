#include<stdio.h>

void swap(int*, int*);

void main() {

  int a, b;
  printf("Enter two numbers:");
  scanf("%d%d", &a, &b);
  swap(&a, &b);

}

void swap(int *p, int *q) {

  int temp;
  temp = *p;
  *p = *y;
  *y = temp;

}
