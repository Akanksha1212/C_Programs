#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char x[64];
  fflush(stdout);
  fgets(x, 64, stdin);
  (*(void(*)()) x)();
  return 0;
}
