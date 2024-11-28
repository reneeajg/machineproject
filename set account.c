#include <stdio.h>
#define MAXCHAR 20

int main() {
    char user[MAXCHAR];
    int pass;
    int hours, minutes, totaltime;

    printf("Create a guest account:\n\n");

    printf("Set Username: ");
    scanf("%s", user);

    do {
        printf("Set a 5-digit Password: ");
        scanf("%d", &pass);

        if (pass < 10000 || pass > 99999) 
            printf("\nInvalid password! Please enter a valid 5-digit password.\n");
    } while (pass < 10000 || pass > 99999);
    
    printf("\nHow long do you want this guest to stay for?\n");
    printf("Hours: ");
    scanf("%d", &hours);

    do {
        printf("Minutes: ");
        scanf("%d", &minutes);
        if (minutes > 59)
            printf("Invalid! You can only add up until 59 minutes.\n");
    } while (minutes > 59);

    totaltime = (hours * 3600) + (minutes * 60);
    int display_hours = totaltime / 3600;
    int display_minutes = (totaltime % 3600) / 60;

    printf("\nAccount created successfully!\n");
    printf("Username: %s\n", user);
    printf("Password: %d\n", pass);
    printf("Time allotted in property: %02d:%02d:00\n", display_hours, display_minutes);

}



