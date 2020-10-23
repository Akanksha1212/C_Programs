#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void){

    string array[] = {"hay", "junk", "hay", "hay", "moreJunk", "needle", "randomJunk"};


    int length = sizeof(array) / sizeof(array[0]);


    for (int i = 0; i < length; i++){
        if(strcmp(array[i], "needle") == 0){
            printf("You found the needle at index %i!\n", i);
            return 0;
        }
    }

}






