/*C program to split string into words.*/
#include <stdio.h>
#include <string.h>
 
int main()
{
    char str[100];
    char words[10][10]; 
    int i,j,cnt;
 
    printf("Enter String: ");
    gets(str);
 
    j=0; cnt=0;
    for(i=0;i<=(strlen(str));i++)
    {
     
        if(str[i]==' '||str[i]=='\0')
        {
            words[cnt][j]='\0';
            cnt++;  
            j=0;    
        }
        else
        {
            words[cnt][j]=str[i];
            j++;
        }
    }
 
    printf("\nWords\n");
    for(i=0;i < cnt;i++)
        printf("%s\n",words[i]);
    return 0;
}
