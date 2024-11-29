#include <stdio.h>
#include <string.h>

#define MAX_USERS 5
#define MAX_SENSORS 5

// Struct to hold account details
typedef struct {
    char username[50];
    char password[50];
    char name[50];
    char address[100];
} Account;

// Struct to hold sensor details
typedef struct {
    int sensor_id;
    char description[100];
    int status; // 0 = inactive, 1 = active
} Sensor;

// Declare global arrays
Account admin_accounts[2];
Account security_accounts[MAX_USERS];
Account guest_accounts[MAX_USERS];
Sensor sensors[MAX_SENSORS];

// Function prototypes
void loginAdmin();
void mainMenu();
void createAccount();
void changePassword();
void sensorSetup();
void showReports();
void logout();

int main() {
    loginAdmin();
    return 0;
}

// Admin login function
void loginAdmin() {
    char username[50];
    char password[50];
    int isAuthenticated = 0;
    
    printf("Enter Admin Username: ");
    scanf("%s", username);
    printf("Enter Admin Password: ");
    scanf("%s", password);

    // Default username and password
    if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0) {
        isAuthenticated = 1;
    }

    if (isAuthenticated) {
        mainMenu();
    } else {
        printf("Invalid login. Exiting...\n");
        exit(0);
    }
}

// Admin menu
void mainMenu() {
    int choice;
    do {
        printf("\nAdmin Menu\n");
        printf("1. User Manual\n");
        printf("2. User Profile\n");
        printf("3. Change Password\n");
        printf("4. Create Account\n");
        printf("5. Sensor Setup\n");
        printf("6. View Reports\n");
        printf("7. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Show user manual
                printf("\nUser Manual: Instructions...\n");
                break;
            case 2: // User profile
                printf("\nAdmin Profile\n");
                printf("Name: %s\n", admin_accounts[0].name);
                printf("Address: %s\n", admin_accounts[0].address);
                break;
            case 3: // Change password
                changePassword();
                break;
            case 4: // Create account
                createAccount();
                break;
            case 5: // Sensor setup
                sensorSetup();
                break;
            case 6: // View reports
                showReports();
                break;
            case 7: // Logout
                logout();
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);
}

// Create account (Admin, Security, or Guest)
void createAccount() {
	int i;
    char username[50], password[50], account_type[10];
    int account_index = -1;

    printf("Enter account type (admin/security/guest): ");
    scanf("%s", account_type);

    if (strcmp(account_type, "admin") == 0) {
        for (i = 0; i < 2; i++) {
            if (admin_accounts[i].username[0] == '\0') {
                account_index = i;
                break;
            }
        }
        if (account_index != -1) {
            printf("Enter username: ");
            scanf("%s", admin_accounts[account_index].username);
            printf("Enter password: ");
            scanf("%s", admin_accounts[account_index].password);
            printf("Enter name: ");
            scanf("%s", admin_accounts[account_index].name);
            printf("Enter address: ");
            scanf("%s", admin_accounts[account_index].address);
            printf("Admin account created successfully.\n");
        } else {
            printf("Maximum number of admin accounts reached.\n");
        }
    } else if (strcmp(account_type, "security") == 0) {
        for (i = 0; i < MAX_USERS; i++) {
            if (security_accounts[i].username[0] == '\0') {
                account_index = i;
                break;
            }
        }
        if (account_index != -1) {
            printf("Enter username: ");
            scanf("%s", security_accounts[account_index].username);
            printf("Enter password: ");
            scanf("%s", security_accounts[account_index].password);
            printf("Security account created successfully.\n");
        } else {
            printf("Maximum number of security accounts reached.\n");
        }
    } else if (strcmp(account_type, "guest") == 0) {
        for (i = 0; i < MAX_USERS; i++) {
            if (guest_accounts[i].username[0] == '\0') {
                account_index = i;
                break;
            }
        }
        if (account_index != -1) {
            printf("Enter username: ");
            scanf("%s", guest_accounts[account_index].username);
            printf("Enter password: ");
            scanf("%s", guest_accounts[account_index].password);
            printf("Guest account created successfully.\n");
        } else {
            printf("Maximum number of guest accounts reached.\n");
        }
    }
}

// Change password
void changePassword() {
    char new_password[50];
    printf("Enter new password: ");
    scanf("%s", new_password);
    strcpy(admin_accounts[0].password, new_password); // Update password for the first admin account
    printf("Password changed successfully.\n");
}

// Sensor setup (activate/deactivate sensors)
void sensorSetup() {
	int i;
    int choice;
    printf("Sensor Setup:\n");
    for (i = 0; i < MAX_SENSORS; i++) {
        printf("Sensor %d: %s (Status: %s)\n", sensors[i].sensor_id, sensors[i].description, 
            (sensors[i].status == 0 ? "Inactive" : "Active"));
    }
    printf("\n1. Activate Sensor\n2. Deactivate Sensor\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        int sensor_id;
        printf("Enter sensor ID to activate: ");
        scanf("%d", &sensor_id);
        if (sensor_id >= 1 && sensor_id <= MAX_SENSORS) {
            sensors[sensor_id - 1].status = 1;
            printf("Sensor %d activated.\n", sensor_id);
        }
    } else if (choice == 2) {
        int sensor_id;
        printf("Enter sensor ID to deactivate: ");
        scanf("%d", &sensor_id);
        if (sensor_id >= 1 && sensor_id <= MAX_SENSORS) {
            sensors[sensor_id - 1].status = 0;
            printf("Sensor %d deactivated.\n", sensor_id);
        }
    }
}

// Show reports
void showReports() {
    // Sample report
    printf("Showing reports...\n");
}

// Logout
void logout() {
    printf("Logging out...\n");
    exit(0);
}

