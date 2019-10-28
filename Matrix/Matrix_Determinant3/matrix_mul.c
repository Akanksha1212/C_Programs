#include <stdio.h>

float det3(float **mat){
  return mat[0][0] * mat[1][1] *mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[0][2] * mat[1][0] * mat[2][1] - (mat[0][2] * mat[1][1] * mat[2][0] + mat[0][1] * mat[2][2] * mat[1][0] + mat[0][0] * mat[1][2] * mat[2][1]);
}

int main(void) {
  
}