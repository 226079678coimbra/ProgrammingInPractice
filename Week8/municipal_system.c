#include <stdio.h>
#include <string.h>


void calculateSalary();
void calculateVAT();
void calculateBudget();
void searchEmployee();
void supplierManagement();

int main() {
    int choice;

    do {
        printf("\n============================================\n");
        printf("    MUNICIPAL FINANCIAL MANAGEMENT SYSTEM   \n");
        printf("============================================\n");
        printf("1. Calculate Employee Salary\n");
        printf("2. Calculate VAT\n");
        printf("3. Calculate Budget\n");
        printf("4. Search Employee\n");
        printf("5. Supplier Management\n");
        printf("6. Exit\n");
        printf("============================================\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                calculateSalary();
                break;
            case 2:
                calculateVAT();
                break;
            case 3:
                calculateBudget();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                supplierManagement();
                break;
            case 6:
                printf("\nExiting system. Thank you!\n");
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}


void calculateSalary() {
    printf("\n--- 1. Calculate Employee Salary ---\n");
    float basic, allowance, tax, netSalary;
    
    printf("Enter Basic Salary: ");
    scanf("%f", &basic);
    printf("Enter Allowance: ");
    scanf("%f", &allowance);
    printf("Enter Tax Deduction: ");
    scanf("%f", &tax);

    netSalary = (basic + allowance) - tax;
    printf("-> Net Salary: $%.2f\n", netSalary);
}


void calculateVAT() {
    printf("\n--- 2. Calculate VAT ---\n");
    float amount, vatRate, vatAmount, totalAmount;

    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("Enter VAT percentage (e.g., 15 for 15%%): ");
    scanf("%f", &vatRate);

    vatAmount = amount * (vatRate / 100.0);
    totalAmount = amount + vatAmount;

    printf("-> VAT Amount: $%.2f\n", vatAmount);
    printf("-> Total Amount (Incl. VAT): $%.2f\n", totalAmount);
}


void calculateBudget() {
    printf("\n--- 3. Calculate Budget ---\n");
    float totalAllocated, totalSpent, remaining;

    printf("Enter Total Allocated Budget: ");
    scanf("%f", &totalAllocated);
    printf("Enter Total Amount Spent: ");
    scanf("%f", &totalSpent);

    remaining = totalAllocated - totalSpent;
    printf("-> Remaining Budget: $%.2f\n", remaining);
}


void searchEmployee() {
    printf("\n--- 4. Search Employee ---\n");
    
    char employees[3][50] = {"John Smith", "Alice Johnson", "David Brown"};
    char searchName[50];
    int found = 0;

    printf("Enter employee name to search: ");
    scanf(" %[^\n]s", searchName);

    for (int i = 0; i < 3; i++) {
        if (strcasecmp(employees[i], searchName) == 0) {
            printf("-> Employee Found: %s\n", employees[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("-> Employee '%s' not found in records.\n", searchName);
    }
}


void supplierManagement() {
    printf("\n--- 5. Supplier Management ---\n");

    char supplierName[50], town[50];
    
    printf("Enter Supplier Name: ");
    scanf(" %[^\n]s", supplierName);
    printf("Enter Supplier Town: ");
    scanf(" %[^\n]s", town);

    printf("-> Supplier '%s (%s)' registered successfully!\n", supplierName, town);
}