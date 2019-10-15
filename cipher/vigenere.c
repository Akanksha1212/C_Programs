#include <cs50.h>
#include <stdio.h>
#include<ctype.h>
#include<string.h>

int shift(char c);
int main(int argc, string argv[])
{
    if(argc==2)
    {
        for(int y=0;argv[1][y]!='\0';y++)
        {
            if(!isalpha(argv[1][y]))
               {
                   printf("Usage: ./caesar key\n");
                   return 1;
               }
            
        } 
        int n = strlen(argv[1]);
        int k[n];
        for(int x=0;x<n;x++)
        {
            k[x] = shift(argv[1][x]);
        }
        string plaintext = get_string("plaintext: ");
        bool lar = false;
        for(int x=0,y=0;plaintext[x]!='\0';x++)
        {
           if(isalpha(plaintext[x]))
           {
               if(isupper(plaintext[x])&& islower(plaintext[x] + k[y%n]))
               {
                   plaintext[x] = plaintext[x]-(26-k[y%n]);
                   
               }
               else
               {
                    plaintext[x] = plaintext[x] + k[y%n];
               }
               y++;
               if(!isalpha(plaintext[x]))
               {
                   plaintext[x]-= 26;
               }
               
           }
        }
        printf("ciphertext: %s\n",plaintext);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //}

}       
    


int shift(char c)
{
    c = toupper(c);
    return  c - 65;
}
