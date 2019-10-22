#include <stdio.h>

int main()
{
   int i, x;
   char str[100];

   printf("Enter string to encrypt or decrypt:\t");
   gets(str);

   printf("\n Choose options:\n");
   printf("1 = Encrypt string.\n");
   printf("2 = Decrypt string.\n");
   scanf("%d", &x);

   switch(x)
   {
   case 1:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] + 3;

      printf("\nEncrypted string: %s\n", str);
      break;

   case 2:
      for(i = 0; (i < 100 && str[i] != '\0'); i++)
        str[i] = str[i] - 3;

      printf("\nDecrypted string: %s\n", str);
      break;

   default:
      printf("\nError,give the Right choice\n");
   }
   return 0;
}