#include <stdio.h>
#include <string.h>
void linearSearch(char array[], int size, char search, int index){
    if (index >= size){
        printf("Target Element Not Found");
        return;
    }
    if (array[index] == search){
        printf("Target Element Found");
        return;
    }else{
        linearSearch(array, size, search, index + 1);
    }
}
int main(){
    char array[20], element;
    printf("Enter string and the element you want to search in the string\n");
    scanf("%s", array);
    getchar();
    scanf("%c", &element);
    linearSearch(array, strlen(array), element, 0);
}