#include <stdio.h>
#include <unistd.h> // For sleep function that allows a 1 second delay

int main() {
    int hours, minutes, totaltime;

    // Input hours and minutes
    printf("Enter amount of hours: ");
    scanf("%d", &hours);

    printf("Enter amount of minutes: ");
    scanf("%d", &minutes);

    // Convert to total time in seconds
    totaltime = (hours * 3600) + (minutes * 60);

    // Countdown loop
    for (; totaltime > 0; totaltime--) {
        int display_hours = totaltime / 3600;
        int display_minutes = (totaltime % 3600) / 60;
        int display_seconds = totaltime % 60;

        // Display remaining time
        printf("\rTime Left: %02d:%02d:%02d", display_hours, display_minutes, display_seconds); //\r for update
        sleep(1);      // Wait for 1 second
    }

    // Time's up message
    printf("\nTime's up!\n");
}


