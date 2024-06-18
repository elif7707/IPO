//
//  main.c
//  IPO
//
//  Created by Elif Zeynep Çetinkaya on 24.05.2024.
//

#include <stdio.h>
#include <string.h>

#define MAX_IPOS 100
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 10
#define MAX_UNDERWRITER_LENGTH 50

// Struct for storing IPO data
struct IPO {
    char company_name[MAX_NAME_LENGTH];
    char stock_symbol[MAX_SYMBOL_LENGTH];
    float offering_price;
    int num_shares;
    char underwriters[MAX_UNDERWRITER_LENGTH];
};

// Array to store IPOs
struct IPO ipos[MAX_IPOS];
int num_ipos = 0;

// Function to add a new IPO
void addIPO() {
    if (num_ipos >= MAX_IPOS) {
        printf("Maximum number of IPOs reached.\n");
        return;
    }

    struct IPO new_ipo;

    printf("Enter company name: ");
    scanf("%s", new_ipo.company_name);

    printf("Enter stock symbol: ");
    scanf("%s", new_ipo.stock_symbol);

    printf("Enter offering price: ");
    scanf("%f", &new_ipo.offering_price);

    printf("Enter number of shares: ");
    scanf("%d", &new_ipo.num_shares);

    printf("Enter underwriters: ");
    scanf("%s", new_ipo.underwriters);

    ipos[num_ipos++] = new_ipo;
    printf("IPO added successfully.\n");
}

// Function to search and retrieve IPO details by company name or stock symbol
void searchIPO() {
    char search_query[100];
    int found = 0;

    printf("Enter company name or stock symbol to search: ");
    scanf("%s", search_query);

    for (int i = 0; i < num_ipos; i++) {
        if (strcmp(ipos[i].company_name, search_query) == 0 || strcmp(ipos[i].stock_symbol, search_query) == 0) {
            printf("Company Name: %s\n", ipos[i].company_name);
            printf("Stock Symbol: %s\n", ipos[i].stock_symbol);
            printf("Offering Price: %.2f\n", ipos[i].offering_price);
            printf("Number of Shares: %d\n", ipos[i].num_shares);
            printf("Underwriters: %s\n", ipos[i].underwriters);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("IPO not found.\n");
    }
}

// Function to display menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add New IPO\n");
    printf("2. Search IPO\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIPO();
                break;
            case 2:
                searchIPO();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
