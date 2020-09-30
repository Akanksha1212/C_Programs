//reverse string without a function
#include <stdio.h>
#include <string.h>
int main()
{
   char s[100];
   scanf("%s",s);
   int n=strlen(s);
   for(int i=0;i<n/2;i++){
       char a=s[i];
       s[i]=s[n-1-i];
       s[n-1-i]=a;
   }
   printf("%s",s);

    return 0;
}
