
#include <stdio.h>

// Structure to store account information
struct Account {
    int pin;
    int balance;
};

// Function to check balance
void checkBalance(struct Account *acc) {
    printf("\nYour current balance is: Rs. %d\n",
           acc->balance);
}

// Function to deposit money
void deposit(struct Account *acc) {
    int amount;

    printf("\nEnter amount to deposit: Rs. ");
    scanf("%d", &amount);

    if (amount > 0) {
        acc->balance += amount;
        printf("Amount deposited successfully!\n");
    } else {
        printf("Invalid deposit amount!\n");
    }
}

// Function to withdraw money
void withdraw(struct Account *acc) {
    int amount;

    printf("\nEnter amount to withdraw: Rs. ");
    scanf("%d", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
    }
    else if (amount > acc->balance) {
        printf("Insufficient balance!\n");
    }
    else {
        acc->balance -= amount;
        printf("Please collect your cash.\n");
    }
}

// Function to change PIN
void changePin(struct Account *acc) {
    int newPin;

    printf("\nEnter your new 4-digit PIN: ");
    scanf("%d", &newPin);

    if (newPin >= 1000 && newPin <= 9999) {
        acc->pin = newPin;
        printf("PIN changed successfully!\n");
    } else {
        printf("Please enter a valid 4-digit PIN.\n");
    }
}

int main() {

    struct Account user = {1234, 5000};

    int enteredPin, attempts = 0;
    int loggedIn = 0;
    int choice;

    printf("================================\n");
    printf("       WELCOME TO MINI ATM      \n");
    printf("================================\n");

    // PIN authentication
    while (attempts < 3) {

        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == user.pin) {
            loggedIn = 1;
            printf("\nLogin successful!\n");
            break;
        } else {
            attempts++;
            printf("Incorrect PIN! Attempts left: %d\n",
                   3 - attempts);
        }
    }

    if (loggedIn == 0) {
        printf("\nAccount access blocked!\n");
        return 0;
    }

    // ATM menu
    do {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                checkBalance(&user);
                break;

            case 2:
                deposit(&user);
                break;

            case 3:
                withdraw(&user);
                break;

            case 4:
                changePin(&user);
                break;

            case 5:
                printf("\nThank you for using Mini ATM!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
