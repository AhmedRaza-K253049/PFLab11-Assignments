#include <stdio.h>
int countVowel(char string[], int index){
    int isVowel;
    if(string[index] == '\0'){
        return 0;
    }
    char letter = string[index];
    isVowel = (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');
    return isVowel + countVowel(string, index + 1);
}
int main(){
    char string[50];
    printf("Enter string to count vowels: ");
    scanf("%s", string);
    printf("Total number of vowels in string are: %d", countVowel(string, 0));
}