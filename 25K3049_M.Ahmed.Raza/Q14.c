#include <stdio.h>
#include <string.h>
#include <time.h>
int main(){
    FILE *fptr;
    fptr = fopen("testfile.txt", "a");
    if (fptr == NULL){
        printf("File not found");
        return 0;
    }
    time_t currentTime;
    time(&currentTime);
    fprintf(fptr, ctime(&currentTime));
    fclose(fptr);
}