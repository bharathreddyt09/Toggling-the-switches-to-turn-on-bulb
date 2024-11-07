#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct {
    char name[50];
    float price;
    int quantity;
} Product;


void addProduct(Product inventory[], int *num) {
    if (*num>= MAXSIZE) {
        printf("Inventory is full!\n");
        return;
    }

    printf("\nEnter product details:\n");
    printf("Name: ");
    getchar();
    scanf(" %s", inventory[*num].name);
    printf("Price: $");
    scanf("%f", &inventory[*num].price);
    printf("Quantity: ");
    scanf("%d", &inventory[*num].quantity);

    (*num)++;
    printf("Product added successfully!\n");
}


void displayInventory(Product inventory[], int num) {
    if (num== 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\nInventory:\n");
    for (int i = 0; i < num; i++) {
        printf("Product: %s | Price: $%.2f | Quantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}


float calculateTotalValue(Product inventory[], int num) {
    float total = 0;
    for (int i = 0; i < num; i++) {
        total += (inventory[i].price * inventory[i].quantity);
    }
    return total;
}


void searchItem(Product inventory[], int num, char name[]) {
    int found = 0;
    printf("\nSearch Results:\n");
    for (int i = 0; i < num; ++i) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }
    if (found==0) {
        printf("Item not found in inventory.\n");
    }
}



int main() {
    Product inventory[MAXSIZE];
    int num = 0;
    int choice;
    char name[50];

    while(1){
        printf("\nInventory Management System\n");
        printf("1. Add Product\n");
        printf("2. Display Inventory\n");
        printf("3. Calculate Total Inventory Value\n");
        printf("4. search product\n");
        printf("5. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(inventory, &num);
                break;
            case 2:
                displayInventory(inventory, num);
                break;
            case 3:
                printf("Total inventory value: $%0.2f\n", calculateTotalValue(inventory, num));
                break;
            case 4:
                printf("Enter the name of the item to search: ");
                getchar();
                scanf(" %s", name);
                searchItem(inventory, num, name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
