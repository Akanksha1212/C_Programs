String reversal using strrev

#include <stdio.h>
#include <string.h>
 
int main()
{
   char array[100];
 
   printf("Enter a string: ");
   gets(array);
 
   strrev(array);
 
   printf("Reverse of the string: %s", array);
 
   return 0;
}
