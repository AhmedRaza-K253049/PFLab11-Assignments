#include <stdio.h>
#include <string.h>
void reverse(char array[], int start, int end){
    if (start >= end){
        return;
    }
    char temp = array[start];
    array[start] = array[end];
    array[end] = temp;
    reverse(array, start + 1, end - 1);
}
int main(){
    char array[30];
    printf("Enter string to reverse: ");
    scanf("%s", array);
    reverse(array, 0, strlen(array) - 1);
    printf("%s", array);
}