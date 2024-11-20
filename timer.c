#include <stdio.h>
#include <string.h>
#include <time.h>

void startTimer(int duration) {
    time_t start_time, current_time;
    time(&start_time);  

    printf("\nYou are authorized %d seconds in this property...\n", duration);

    do {
        time(&current_time);
    } while (difftime(current_time, start_time) < duration);

    printf("\nTime's up! You have been logged out.\n");
}

int main() {
    char guestName[20], guestNameInput[20];  
    int password, passwordInput, timerDuration;

    printf("CREATE A GUEST ACCOUNT\n\nEnter guest name: ");
    scanf("%s", guestName);  

    printf("\nSet a password: ");
    scanf("%d", &password);  

    printf("\nGuest Account Created\n");
    printf("Guest Name: %s\n", guestName);
    printf("Password: %d\n", password);

    printf("\nAdmin, enter the session timeout duration in seconds: ");
    scanf("%d", &timerDuration);

    printf("\n\nGUEST POV:\n\nEnter name: ");
    scanf("%s", guestNameInput); 

    printf("Enter password: ");
    scanf("%d", &passwordInput);  

    if (strcmp(guestName, guestNameInput) == 0 && password == passwordInput) {
        printf("\nYou are logged in!\n");

        startTimer(timerDuration);
    } else {
        printf("Invalid credentials!\n");
    }

}

