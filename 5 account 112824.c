#include <stdio.h>
#include <string.h>  // For using strcmp function
#define MAXCHAR 20
#define MAXACCOUNTS 5

int main() {
    char users[MAXACCOUNTS][MAXCHAR];    // Array to store usernames
    int passwords[MAXACCOUNTS];           // Array to store passwords
    int hours[MAXACCOUNTS], minutes[MAXACCOUNTS], totaltime[MAXACCOUNTS];  // Arrays for time
    int account_count = 0;  // Counter for created accounts
    char choice;            // Variable to choose whether to continue creating accounts
    int i;

    printf("Guest Account Creation Program\n");

    while (account_count < MAXACCOUNTS) {
        printf("\nCreating Account %d of %d:\n", account_count + 1, MAXACCOUNTS);

        // Set Username with validation to ensure uniqueness
        int username_exists;
        do {
            printf("Set Username: ");
            scanf("%s", users[account_count]);

            // Check for duplicate username
            username_exists = 0;  // Reset the flag for each username check
            for (i = 0; i < account_count; i++) {
                if (strcmp(users[account_count], users[i]) == 0) {
                    username_exists = 1;  // Set the flag if username exists
                    break;  // Exit the loop as we found a duplicate
                }
            }

            if (username_exists) {
                printf("Username already taken! Please choose a different username.\n");
            }
        } while (username_exists);  // Continue asking for a new username if duplicate exists

        // Set 5-digit Password with validation
        int password_exists;
        do {
            printf("Set a 5-digit Password: ");
            scanf("%d", &passwords[account_count]);  // User enters password

            // Check if the password is a valid 5-digit number
            if (passwords[account_count] < 10000 || passwords[account_count] > 99999) {
                printf("\nInvalid password! Please enter a valid 5-digit password.\n");
            } else {
                // Check for duplicate password
                password_exists = 0;  // Reset the flag for each password check
                for (i = 0; i < account_count; i++) {
                    if (passwords[account_count] == passwords[i]) {
                        password_exists = 1;  // Set the flag if password exists
                        break;  // Exit the loop as we found a duplicate
                    }
                }

                if (password_exists) {
                    printf("Password already taken! Please choose a different password.\n");
                }
            }
        } while (passwords[account_count] < 10000 || passwords[account_count] > 99999 || password_exists);

        // Ensure that hours and minutes are not both zero
        do {
            printf("Set Time - Hours: ");
            scanf("%d", &hours[account_count]);
            
            if (hours[account_count] < 0) {
                printf("Invalid! Hours cannot be negative.\n");
                continue;
            }

            do {
                printf("Set Time - Minutes: ");
                scanf("%d", &minutes[account_count]);
                
                if (minutes[account_count] < 0 || minutes[account_count] > 59) {
                    printf("Invalid! You can only add up to 59 minutes.\n");
                }
            } while (minutes[account_count] < 0 || minutes[account_count] > 59);

            // Check if both hours and minutes are zero
            if (hours[account_count] == 0 && minutes[account_count] == 0) {
                printf("Invalid! Time cannot be 00:00. Please enter a valid time.\n");
            }
        } while (hours[account_count] == 0 && minutes[account_count] == 0);

        // Calculate total time in seconds
        totaltime[account_count] = (hours[account_count] * 3600) + (minutes[account_count] * 60);

        // Display the real-time account details
        printf("\nAccount %d created successfully!\n", account_count + 1);
        printf("Username: %s\n", users[account_count]);
        printf("Password: %d\n", passwords[account_count]);
        printf("Time allotted in property: %02d:%02d:00\n",
               totaltime[account_count] / 3600,  // Calculate hours
               (totaltime[account_count] % 3600) / 60);  // Calculate minutes

        account_count++;  // Increment account count

        // Ask if the user wants to create another account
        if (account_count < MAXACCOUNTS) {
            printf("\nDo you want to create another account? (Y/N): ");
            scanf(" %c", &choice);  // Space before %c to skip any leftover newline character
            if (choice == 'N' || choice == 'n') {
                printf("Account creation process stopped.\n");
                break;  // Exit if the user chooses to stop account creation
            }
        }
    }

    printf("\nAll accounts created successfully!\n");

    return 0;
}


