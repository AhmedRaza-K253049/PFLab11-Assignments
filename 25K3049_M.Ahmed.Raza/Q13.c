#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    char text[100];
    FILE *fptr;
    fptr = fopen("testfile.txt", "w");
    if(fptr == NULL){
        printf("File Not Found");
        return 0;
    }
    fclose(fptr);
    fptr = fopen("testfile.txt", "w");
    if(fptr == NULL){
        printf("File Not Found");
        return 0;
    }
    while(fgets(text, 100, fptr)){
        printf("%s", text);
    }
}