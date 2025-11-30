#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE *fptr;
    int word = 0, line = 0, character = 0, inWord = 0;
    fptr = fopen("testfile.txt", "r");
    char text[100];
    if(fptr == NULL){
        return 1;
    }
    while(fgets(text, 100, fptr)){
        line++;
        for(int i = 0; text[i] != '\0'; i++){
            character++;
            if(text[i] == ' ' || text[i] == '\n'){
                inWord = 0;
            }else{
                if(inWord == 0){
                    word++;
                }
                inWord = 1;
            }
        }
    }
    fclose(fptr);
    printf("Total Lines are: %d\nTotal Words are %d\nTotal Character are: %d", line, word, character);
}