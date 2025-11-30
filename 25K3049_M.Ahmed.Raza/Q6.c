#include <stdio.h>
#include <string.h>
struct salaryStruct{
    int basic;
    int bonus;
    int deductions;
};
struct employee{
    int ID;
    char name[30];
    struct salaryStruct salary;
};
void netSalary(struct employee employeeArray[], int employeeCount){
    int total;
    for(int i = 0; i < employeeCount; i++){
        total = 0;
        total += employeeArray[i].salary.basic;
        total += employeeArray[i].salary.bonus;
        total -=employeeArray[i].salary.deductions; 
        printf("Total Salary of %s is: %d\n", employeeArray[i].name, total);
    }
}
void addEmployee(struct employee employeeArray[], int *employeeCount){
    char employeeName[30];
    printf("Enter ID of employee: ");
    scanf("%d", &employeeArray[*employeeCount].ID);
    getchar();
    printf("Enter Name of employee: ");
    fgets(employeeName, 30, stdin);
    employeeName[strcspn(employeeName, "\n")] = '\0';
    strcpy(employeeArray[*employeeCount].name, employeeName);
    printf("Enter Basic pay of employee: ");
    scanf("%d", &employeeArray[*employeeCount].salary.basic);
    getchar();
    printf("Enter Bonus pay of employee: ");
    scanf("%d", &employeeArray[*employeeCount].salary.bonus);
    getchar();
    printf("Enter Deduction of employee: ");
    scanf("%d", &employeeArray[*employeeCount].salary.deductions);
    getchar();
    (*employeeCount)++;
}
void displayDetails(struct employee employeeArray[], int employeeCount, int id){
    int found = 0;
    for(int i = 0; i < employeeCount; i++){
        if(employeeArray[i].ID == id){
            printf("Employee ID: %d\nEmployee Name: %s\nBasic Salary: %d\nBonus: %d\nDeductions: %d", employeeArray[i].ID,employeeArray[i].name,employeeArray[i].salary.basic,employeeArray[i].salary.bonus,employeeArray[i].salary.deductions);
            found = 1;
        }
    }
    if(!found){
        printf("Employee Not Found !");
    }
}
int main(){
    int size, choice, searchid, repeat;
    int totalEmployee = 0;
    printf("How many employees will you input ?\n");
    scanf("%d", &size);
    struct employee employeeArray[size];
    for(int i = 0; i < size; i++){
        addEmployee(employeeArray, &totalEmployee);
    }
    do{
        printf("\nDo you want to calculate net salary or display an employees salary details ? Enter 1 or 2 for each respectively\n");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                netSalary(employeeArray, totalEmployee);
                break;
            case 2:
                printf("\nEnter id of employee to search details of: ");
                scanf("%d", &searchid);
                getchar();
                displayDetails(employeeArray, totalEmployee, searchid);
        }
        printf("\nDo you want to continue or exit the application ? Enter 1 or 0 for each respectively\n");
        scanf("%d", &repeat);
    }while(repeat);
}