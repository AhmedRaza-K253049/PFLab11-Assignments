#include <stdio.h>
double meterToKm(){
    static int count = 0;
    double meter;
    count++;
    printf("Enter meter to conver to Km: ");
    scanf("%lf", &meter);
    double km = meter / 1000;
    printf("%.2lf", km);
    printf("\nFunction ran %d times\n", count);
}
int main(){
    meterToKm();
    meterToKm();
    meterToKm();
}