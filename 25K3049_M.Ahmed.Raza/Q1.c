#include <stdio.h>
int sum(int num){
    int value;
    if(num == 0){
        return num;
    }else{
        value = num % 10;
        return value + sum(num / 10);
    }
}
int main(){
    int num, total;
    printf("Enter number to sum: ");
    scanf("%d", &num);
    total = sum(num);
    printf("%d", total);
}