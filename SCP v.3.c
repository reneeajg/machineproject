#include <stdio.h>
#define SENSORS 5 

void sensorManager(int sensorStatus[SENSORS], int sensorNum, int activity);
void sensorCalibration(int sensorStatus[SENSORS]);
void displaySensorsStatus(int sensorStatus[SENSORS]);
void sensorSetup(int sensorStatus[SENSORS]);
void panicButton(void);
void manualDisarm(int sensorStatus[SENSORS]);


void panicButton() {
    printf("\n** PANIC BUTTON ACTIVATED **\n");
    printf("ALERT: The system has detected an emergency! Sensors are now in active alert mode!\n");
    
}


void manualDisarm(int sensorStatus[SENSORS]) {
    int choice, x;
    char allSensors, continueDisarm;

    printf("\nMANUAL DISARM\n");
    printf("Would you like to disarm all sensors or individual ones?\n");
    printf("1. Disarm all sensors\n2. Disarm individual sensors\nChoose [1/2]: ");
    scanf("%d", &choice);

    if (choice == 1) {
        
        printf("Disarming all sensors...\n");
        for (x = 0; x < SENSORS; x++) {
            sensorManager(sensorStatus, x, 0);
        }
    } else if (choice == 2) {
        
        do {
            printf("Disarm which sensor? (0 to %d): ", SENSORS - 1);
            scanf("%d", &choice);
            if (choice >= 0 && choice < SENSORS) {
                sensorManager(sensorStatus, choice, 0);
            } else {
                printf("Invalid sensor number. Please try again.\n");
            }

            printf("Would you like to disarm another sensor? [Y/N]: ");
            scanf(" %c", &continueDisarm);
        } while (continueDisarm == 'Y' || continueDisarm == 'y');
    } else {
        printf("Invalid choice.\n");
    }
}


void sensorManager(int sensorStatus[SENSORS], int sensorNum, int activity) {
    if (sensorNum < 0 || sensorNum >= SENSORS) {
        printf("Error: Invalid Sensor Number!\n");
    }

    if (activity == 1 && sensorStatus[sensorNum] == 0) {
        sensorStatus[sensorNum] = 1;
        printf("Sensor %d ACTIVATED\n", sensorNum);
    } else if (activity == 0 && sensorStatus[sensorNum] == 1) {
        sensorStatus[sensorNum] = 0;
        printf("Sensor %d DEACTIVATED.\n", sensorNum);
    } else {
        if (activity) {
            printf("Sensor %d is already active.\n", sensorNum);
        } else {
            printf("Sensor %d is already inactive.\n", sensorNum);
        }
    }
}

void sensorSetup(int sensorStatus[SENSORS]) {
    int x;
    char AllSensors;
    int activity;

    printf("\nSENSOR SETUP\n");
    printf("Hello Admin. Welcome to the Sensor Setup!\n");

    for (x = 0; x < SENSORS; x++) {
        sensorStatus[x] = 0;
    }

    printf("The security system has 5 programmable sensors.\n");
    printf("Do you want to ACTIVATE all sensors? Choose [Y/N]: ");
    scanf(" %c", &AllSensors);

    if (AllSensors == 'Y' || AllSensors == 'y') {
        for (x = 0; x < SENSORS; x++) {
            sensorManager(sensorStatus, x, 1);
        }
    } else {
        printf("Choose which sensors to activate or deactivate individually.\n");
        for (x = 0; x < SENSORS; x++) {
            printf("Current Status: Sensor %d ", x);
            if (sensorStatus[x] == 1) {
                printf("ACTIVE\n");
            } else {
                printf("INACTIVE\n");
            }

            printf("Choose activity for Sensor %d (0 - Deactivate, 1 - Activate): ");
            scanf("%d", &activity);
            sensorManager(sensorStatus, x, activity);
        }
    }
}

void sensorCalibration(int sensorStatus[SENSORS]) {
    int choice, x;
    char continueC;

    do {
        printf("\nSENSOR CALIBRATION\n");
        printf("Choose a mode [1/2/3]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Idle Mode selected. All sensors are now OFF.\n");
                for (x = 0; x < SENSORS; x++) {
                    sensorManager(sensorStatus, x, 0);
                }
                break;

            case 2:
                printf("Enhanced Security Mode selected.\n");
                for (x = 0; x < SENSORS; x++) {
                    sensorManager(sensorStatus, x, 1);
                }
                break;

            case 3:
                printf("Maximum Security Mode selected.\n");
                for (x = 0; x < SENSORS; x++) {
                    sensorManager(sensorStatus, x, 1);
                }
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }

        displaySensorsStatus(sensorStatus);
        printf("Would you like to calibrate another Security Mode? [Y/N]: ");
        scanf(" %c", &continueC);
    } while (continueC == 'Y' || continueC == 'y');

    printf("Exiting Sensor Calibration.\n");
}

void displaySensorsStatus(int sensorStatus[SENSORS]) {
    int x;
    printf("\nCurrent status of all the sensors:\n");
    for (x = 0; x < SENSORS; x++) {
        printf("Sensor %d: ", x);
        if (sensorStatus[x]) {
            printf("ACTIVE\n");
        } else {
            printf("INACTIVE\n");
        }
    }
}

int main() {
    int choice;
    char continueS;
    int sensorStatus[SENSORS] = {0};

    do {
        printf("\nOptions:\n");
        printf("1. Sensor Setup\n");
        printf("2. Sensor Calibration\n");
        printf("3. Panic Button\n");
        printf("4. Manual Disarm\n");
        printf("Choose [1/2/3/4]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                sensorSetup(sensorStatus);
                displaySensorsStatus(sensorStatus);
                break;

            case 2:
                sensorCalibration(sensorStatus);
                break;

            case 3:
                panicButton();  // Simulate panic button alert
                break;

            case 4:
                manualDisarm(sensorStatus);  // Disarm all or specific sensors
                break;

            default:
                printf("Invalid choice.\n");
        }

        printf("\nWould you like to go back to the main menu? [Y/N]: ");
        scanf(" %c", &continueS);
    } while (continueS == 'Y' || continueS == 'y');

    printf("Exiting...\n");

    return 0;
}

