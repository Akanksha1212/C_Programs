// A beginner level C program to find out the most occuring character in a string

#include <stdio.h>

int main() {
    char str[100];
    int count[26] = {0};
    int i,max=0;
    
    printf("Enter a string (lowercase only) : ");
    scanf("%s", &str);
    
    //stores the count of each character
    for(i=0; i<strlen(str); i++){
        count[str[i]-97]++;
    }
    
    //finds the maximum count
    for(i=0; i<26; i++){
        if(count[i]>max){
            max = count[i];
        }
    }
    
    printf("Most occuring character(s) is/are : ");
    
    //finds the character with max count
    for(i=0; i<26; i++){
        if(count[i] == max){
            printf("%c ", i+97);
        }
    }
    
    printf("(%d times)", max);
    
    return 0;
}