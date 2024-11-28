#include <stdio.h>
#define MAXCHAR 20
#define MAXACCOUNTS 5

int main() {
    char users[MAXACCOUNTS][MAXCHAR];
    int passwords[MAXACCOUNTS];
    int hours[MAXACCOUNTS], minutes[MAXACCOUNTS], totaltime[MAXACCOUNTS];
    int account_count = 0;
    char choice;

    printf("Guest Account Creation Program\n");

    while (account_count < MAXACCOUNTS) {
        printf("\nCreating Account %d of %d:\n", account_count + 1, MAXACCOUNTS);

        printf("Set Username: ");
        scanf("%s", users[account_count]);

        do {
            printf("Set a 5-digit Password: ");
            scanf("%d", &passwords[account_count]);

            if (passwords[account_count] < 10000 || passwords[account_count] > 99999)
                printf("\nInvalid password! Please enter a valid 5-digit password.\n");
        } while (passwords[account_count] < 10000 || passwords[account_count] > 99999);

        printf("\nHow long do you want this guest to stay for?\n");
        printf("Hours: ");
        scanf("%d", &hours[account_count]);

        do {
            printf("Minutes: ");
            scanf("%d", &minutes[account_count]);
            if (minutes[account_count] > 59)
                printf("Invalid! You can only add up until 59 minutes.\n");
        } while (minutes[account_count] > 59);

        totaltime[account_count] = (hours[account_count] * 3600) + (minutes[account_count] * 60);

        printf("\nAccount %d created successfully!\n", account_count + 1);
        printf("Username: %s\n", users[account_count]);
        printf("Password: %d\n", passwords[account_count]);
        printf("Time allotted in property: %02d:%02d:00\n",
               totaltime[account_count] / 3600,
               (totaltime[account_count] % 3600) / 60);

        account_count++;

        if (account_count < MAXACCOUNTS) {
            printf("\nDo you want to create another account? (Y/N): ");
            scanf(" %c", &choice); // Space before %c to skip any leftover newline character
            if (choice == 'N' || choice == 'n') {
                printf("Account creation process stopped.\n");
                break; // Exit the loop if user chooses to stop
            }
        }
    }

    printf("\nAll accounts created successfully!\n");
}


