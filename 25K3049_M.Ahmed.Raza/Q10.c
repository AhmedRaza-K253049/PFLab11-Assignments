#include <stdio.h>
#include <string.h>
int palindrome(char array[]){
    int start = 0, end = strlen(array) - 1;
    do{
        if(array[start] == array[end]){
            start += 1;
            end -= 1;
        }else{
            return 0;
        }
    }while(start <= end);
    return 1;
}
int main(){
    int all = 1;
    char array[5][20];
    for(int i = 0; i < 5; i++){
        printf("Enter you word to check for palindrome: ");
        scanf("%s", array[i]);
        getchar();
    }
    for(int i = 0; i < 5; i++){
        if(!palindrome(array[i])){
            all = 0;
        }
    }
    if(all){
        printf("All words were a palindrome");
    }else{
        printf("Not all words were a palindrome");
    }
}