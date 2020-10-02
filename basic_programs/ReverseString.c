#include<stdio.h>
#include<string.h>

main(){

    char mystrg[60];
    int leng, x;

    printf("Please insert the string you want to reverse: ");
    scanf( "%s", mystrg );
    leng = strlen(mystrg);
    for(x=leng-1; x>=0; x--){
        printf("%c", mystrg[x]);
    }
}
