#include <stdio.h>
#include <string.h>

int check(char string[], char search[]){
    int index = 0;
    char extract[strlen(search)];
    if(strstr(string, search)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    char string[20], search[20];
    printf("Enter string to search word in: ");
    scanf("%s", string);
    getchar();
    printf("Enter word to search for: ");
    scanf("%s", search);
    if(check(string, search)){
        printf("Found");
    }else{
        printf("Not Found");
    }
}