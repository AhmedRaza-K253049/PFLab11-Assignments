#include <stdio.h>
#include <string.h>
int main(){
    FILE *file1, *file2, *file3;
    char text[100];
    file1 = fopen("testfile.txt", "a");
    file2 = fopen("testfile2.txt", "r");
    file3 = fopen("testfile3.txt", "r");
    if (file1 == NULL){
        printf("File not found");
        return 0;
    }
    if (file2 == NULL){
        printf("File not found");
        return 0;
    }
    if (file3 == NULL){
        printf("File not found");
        return 0;
    }
    while(fgets(text, 100 , file2)){
        fprintf(file1, text);
    }
    fputc('\n', file1);
    while(fgets(text, 100 , file3)){
        fprintf(file1, text);
    }
}