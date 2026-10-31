#include <stdio.h>
#include <string.h>

#define NUM_SUPPLIERS 5


struct Supplier {
    char name[50];
    char email[50];
    char phone[20];
    char town[50];
};

int main() {
    struct Supplier suppliers[NUM_SUPPLIERS];
    int i;
    char searchName[50];
    int found = 0;

    printf("=========================================\n");
    printf("     SUPPLIER INFORMATION MANAGEMENT     \n");
    printf("=========================================\n\n");

    
    printf("Please enter information for %d suppliers:\n\n", NUM_SUPPLIERS);
    for (i = 0; i < NUM_SUPPLIERS; i++) {
        printf("--- Supplier %d ---\n", i + 1);
        
        printf("Enter Name : ");
        scanf(" %[^\n]s", suppliers[i].name); 
        
        printf("Enter Email: ");
        scanf(" %[^\n]s", suppliers[i].email);
        
        printf("Enter Phone: ");
        scanf(" %[^\n]s", suppliers[i].phone);
        
        printf("Enter Town : ");
        scanf(" %[^\n]s", suppliers[i].town);
        
        printf("\n");
    }

    
    printf("-----------------------------------------\n");
    printf("          ALL SUPPLIERS RECORDS          \n");
    printf("-----------------------------------------\n");
    for (i = 0; i < NUM_SUPPLIERS; i++) {
        printf("Supplier %d:\n", i + 1);
        printf("  Name  : %s\n", suppliers[i].name);
        printf("  Email : %s\n", suppliers[i].email);
        printf("  Phone : %s\n", suppliers[i].phone);
        printf("  Town  : %s\n", suppliers[i].town);
        printf("-----------------------------------------\n");
    }

    
    printf("\n               SEARCH SUPPLIER           \n");
    printf("-----------------------------------------\n");
    printf("Enter supplier name to search: ");
    scanf(" %[^\n]s", searchName);

    found = 0;
    for (i = 0; i < NUM_SUPPLIERS; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("\nSupplier Found!\n");
            printf("  Name  : %s\n", suppliers[i].name);
            printf("  Email : %s\n", suppliers[i].email);
            printf("  Phone : %s\n", suppliers[i].phone);
            printf("  Town  : %s\n", suppliers[i].town);
            found = 1;
        }
    }

    if (!found) {
        printf("\nSupplier '%s' was not found in the records.\n", searchName);
    }
    printf("=========================================\n");

    return 0;
}