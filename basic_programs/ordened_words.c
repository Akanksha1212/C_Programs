//Author: Mateus Gomes do Nascimento || Brasília - Brazil
//email: mateusgomes.nascimento21@gmail.com

/*
Application:
This algorithm tells if the letters of a word are ordened or not
Example: the word "joy" is ordened, because 'j' comes before 'o', wich
comes before 'y'

How to use:
First you have to input how many words are gonna to appear
Then, you have to input the words and the output is gonna be "Ordened" or "Not Ordened"
*/

#include<stdio.h>

int main(){
  int n,len,test;
  int i;
  char word[42],aux[42];

  printf("How many words: ");
  scanf("%d",&n);
  printf("\n");

  for(int j=0;j<n;j++){
    test=0;
    printf("%d word: ",j+1);
    scanf("%s",word);
    len = 0;
    while(word[len]!='\0'){ //Saves the length of the word
      len++;
    }
    for(i=0;i<len;i++) //Saves the word in a auxiliar string (used for transform all the capital letters in normal letters and do not lose the original word)
      aux[i] = word[i];
    for(i=0;i<len;i++)
      if(aux[i]>=65&&aux[i]<=90) //Conversor from capital letter to normal letter
        aux[i]+=32;
    for(i=0;i<len-1;i++)
      if(aux[i]>=aux[i+1]) //Tests if word is ordened or not
        test++;
    if(test==0)
      printf("%s: Ordened\n\n",word);
    else
      printf("%s: Not Ordened\n\n",word);
  }

  return 0;
}
