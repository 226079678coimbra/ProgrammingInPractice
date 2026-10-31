#include <stdio.h>

#define NUM_EMPLOYEES 50

int main() {
    float salaries[NUM_EMPLOYEES];
    int i, j;
    float total = 0, average = 0, highest, lowest;
    float searchTarget;
    int found = 0;

    printf("=========================================\n");
    printf("   EMPLOYEE SALARY MANAGEMENT SYSTEM     \n");
    printf("=========================================\n\n");


    printf("Please enter the salaries for %d employees:\n", NUM_EMPLOYEES);
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Employee %d salary: $", i + 1);
        scanf("%f", &salaries[i]);
    }


    printf("\n-----------------------------------------\n");
    printf("         ALL EMPLOYEE SALARIES           \n");
    printf("-----------------------------------------\n");
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Employee %d: $%.2f\n", i + 1, salaries[i]);
    }


    total = 0;
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        total += salaries[i];
    }

    
    average = total / NUM_EMPLOYEES;

    printf("\n-----------------------------------------\n");
    printf("            SALARY STATISTICS            \n");
    printf("-----------------------------------------\n");
    printf("Total Salary Expenditure : $%.2f\n", total);
    printf("Average Salary           : $%.2f\n", average);


    highest = salaries[0];
    lowest = salaries[0];
    for (i = 1; i < NUM_EMPLOYEES; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }
    printf("Highest Salary           : $%.2f\n", highest);
    printf("Lowest Salary            : $%.2f\n", lowest);

    
    printf("\n-----------------------------------------\n");
    printf("              SEARCH SALARY              \n");
    printf("-----------------------------------------\n");
    printf("Enter a specific salary amount to search for: $");
    scanf("%f", &searchTarget);

    found = 0;
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        if (salaries[i] == searchTarget) {
            printf("Found! Salary $%.2f belongs to Employee %d.\n", searchTarget, i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Salary $%.2f was not found in the records.\n", searchTarget);
    }


    for (i = 0; i < NUM_EMPLOYEES - 1; i++) {
        for (j = 0; j < NUM_EMPLOYEES - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                float temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }


    printf("\n-----------------------------------------\n");
    printf("    SALARIES SORTED (LOWEST TO HIGHEST)  \n");
    printf("-----------------------------------------\n");
    for (i = 0; i < NUM_EMPLOYEES; i++) {
        printf("Rank %2d: $%.2f\n", i + 1, salaries[i]);
    }
    printf("=========================================\n");

    return 0;
}