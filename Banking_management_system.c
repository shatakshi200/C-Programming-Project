#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100

struct customer {
    char name[50];
    int account_number;
    double balance;
};

struct customer customers[MAX_CUSTOMERS];
int num_customers = 0;

void create_account() {
    struct customer c;

    printf("Enter name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';

    printf("Enter account number: ");
    scanf("%d", &c.account_number);

    printf("Enter initial balance: ");
    scanf("%lf", &c.balance);

    getchar(); // Consume newline character

    customers[num_customers] = c;
    num_customers++;

    printf("Account created successfully.\n");
}

void deposit() {
    int account_number;
    double amount;
    int i;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);

            customers[i].balance += amount;

            printf("Deposit successful. New balance: %.2lf\n", customers[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

void withdraw() {
    int account_number;
    double amount;
    int i;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);

            if (customers[i].balance < amount) {
                printf("Insufficient balance. Current Balance: %.2lf\n", customers[i].balance);
            } else {
                customers[i].balance -= amount;
                printf("Withdrawal successful. New balance: %.2lf\n", customers[i].balance);
            }

            return;
        }
    }

    printf("Account not found.\n");
}

void view_balance() {
    int account_number;
    int i;

    printf("Enter account number: ");
    scanf("%d", &account_number);

    for (i = 0; i < num_customers; i++) {
        if (customers[i].account_number == account_number) {
            printf("Balance: %.2lf\n", customers[i].balance);
            return;
        }
    }

    printf("Account not found.\n");
}

int main() {
    int choice;

    while (1) {
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View balance\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                view_balance();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("\n");
    }

    return 0;
}
