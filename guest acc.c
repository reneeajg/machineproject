#include <stdio.h>
#include <unistd.h>  
#define MAXCHAR 20
#define MAXACCOUNTS 5


int compare_strings(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int main() {
    char users[MAXACCOUNTS][MAXCHAR];
    int passwords[MAXACCOUNTS];
    int hours[MAXACCOUNTS], minutes[MAXACCOUNTS], totaltime[MAXACCOUNTS];
    int account_count = 0;
    char choice, back_choice;
    int i, menu_choice;
    int exit = 0;

    do {
        printf("\nMenu\n1. Guest login\n2. Create guest account\n3. Configure sensor access\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                if (account_count == 0) {
                    printf("\nNo accounts available. Please create an account first.\n");
                    break;
                }
                do {
                    char username[MAXCHAR];
                    int password, login_success = 0;

                    printf("\nGUEST LOGIN\n");
                    printf("\nEnter your username: ");
                    scanf("%s", username);
                    printf("Enter your password: ");
                    scanf("%d", &password);

                    for (i = 0; i < account_count; i++) {
                        if (compare_strings(users[i], username) == 0 && passwords[i] == password) {
                            printf("\nLogin successful!\n");
                            printf("Welcome, %s!\n", username);
                            login_success = 1;

                            printf("Starting your allotted time countdown...\n");
                            while (totaltime[i] > 0) {
                                int display_hours = totaltime[i] / 3600;
                                int display_minutes = (totaltime[i] % 3600) / 60;
                                int display_seconds = totaltime[i] % 60;
                                printf("\rTime Left: %02d:%02d:%02d", display_hours, display_minutes, display_seconds);
                                fflush(stdout);
                                sleep(1);
                                totaltime[i]--;
                            }

                            printf("\nTime's up!\n");
                            break;
                        }
                    }

                    if (!login_success) {
                        printf("\nInvalid username or password. Please try again.\n");
                        printf("Enter 'B' to go back to the main menu or 'R' to retry login: ");
                        scanf(" %c", &back_choice);
                    } else {
                        back_choice = 'B';
                    }
                } while (back_choice != 'B' && back_choice != 'b');
                break;

            case 2:
                do {
                    printf("\nGuest Account Creation Program\n");

                    while (account_count < MAXACCOUNTS) {
                        printf("\nCreating Account %d of %d:\n", account_count + 1, MAXACCOUNTS);
                        int username_exists;
                        do {
                            printf("Set Username: ");
                            scanf("%s", users[account_count]);
                            username_exists = 0;
                            for (i = 0; i < account_count; i++) {
                                if (compare_strings(users[account_count], users[i]) == 0) {
                                    username_exists = 1;
                                    break;
                                }
                            }
                            if (username_exists) {
                                printf("Username already taken! Please choose a different username.\n");
                            }
                        } while (username_exists);

                        int password_exists;
                        do {
                            printf("Set a 5-digit Password: ");
                            scanf("%d", &passwords[account_count]);
                            if (passwords[account_count] < 10000 || passwords[account_count] > 99999) {
                                printf("\nInvalid password! Please enter a valid 5-digit password.\n");
                            } else {
                                password_exists = 0;
                                for (i = 0; i < account_count; i++) {
                                    if (passwords[account_count] == passwords[i]) {
                                        password_exists = 1;
                                        break;
                                    }
                                }
                                if (password_exists) {
                                    printf("Password already taken! Please choose a different password.\n");
                                }
                            }
                        } while (passwords[account_count] < 10000 || passwords[account_count] > 99999 || password_exists);

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
                            if (hours[account_count] == 0 && minutes[account_count] == 0) {
                                printf("Invalid! Time cannot be 00:00. Please enter a valid time.\n");
                            }
                        } while (hours[account_count] == 0 && minutes[account_count] == 0);

                        totaltime[account_count] = (hours[account_count] * 3600) + (minutes[account_count] * 60);

                        printf("\nAccount %d created successfully!\n", account_count + 1);
                        printf("Username: %s\n", users[account_count]);
                        printf("Password: %d\n", passwords[account_count]);
                        printf("Time allotted in property: %02d:%02d:00\n",
                               totaltime[account_count] / 3600,
                               (totaltime[account_count] % 3600) / 60);

                        account_count++;

                        if (account_count < MAXACCOUNTS) {
                            printf("\nDo you want to create another account? [Y/B (Back)]: ");
                            scanf(" %c", &choice);
                            if (choice == 'B' || choice == 'b') {
                                break;
                            }
                        }
                    }

                    if (account_count == MAXACCOUNTS) {
                        printf("\nAll accounts created successfully!\n");
                    }
                } while (choice != 'B' && choice != 'b');
                break;

            case 3:
                printf("\nSensor configuration is not implemented yet.\n");
                break;

            case 4:
                printf("\nExiting the program. Goodbye!\n");
                exit = 1;
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (!exit);
}



