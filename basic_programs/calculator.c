#include <stdio.h>

int main()
{
  int num1, num2;
  char act;
  printf("Enter first number : ");
  scanf("%d", &num1);
  printf("Enter second number : ");
  scanf("%d", &num2);
  printf("Enter desired action : ");
  scanf("%d", &act);
  switch (act)
  {
  case '+':
    printf("SUM of the two numbers %d and %d : %d\n", num1, num2, num1 + num2);
    break;
  case '-':
    printf("SUB of the two numbers %d and %d : %d\n", num1, num2, num1 - num2);
    break;
  case '*':
    printf("MUL of the two numbers %d and %d : %d\n", num1, num2, num1 * num2);
    break;
  case '/':
    printf("DIV of the two numbers %d and %d : %d\n", num1, num2, num1 / num2);
    break;
  default:
    printf("Bad action!\n");
    break;
  }
  return 0;
}
