#include <stdio.h>
#define SENSORS 5
int sensorStatus[SENSORS];

void displaySensorsStatus();
void sensorCalibration();
void sensorManager();


void sensorManager(int sensorNum, int activity){
	if (sensorNum < 0 || sensorNum >= SENSORS ){
		printf("Error: Invalid Sensor Number!");
		return;
	}
	
	if(activity == 1 && sensorStatus[sensorNum] == 0){
		sensorStatus[sensorNum] = 1;
		printf("Sensor %d ACTIVATED\n",sensorNum);
	}	else if(activity == 0 && sensorStatus[sensorNum] == 1){
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

void sensorCalibration() {
    int choice;
    int x;
    char bedtime[6]; 
    char continueC;

do {
    printf("\nSENSOR CALIBRATION\n");
    printf("This system offers three calibration modes:\n");
    printf("1. Idle Mode (Homeowner is home, all sensors OFF)\n");
    printf("2. Enhanced Security Mode (Residents asleep, based on inputted bedtime)\n");
    printf("3. Maximum Security Mode (Homeowners away, all sensors ACTIVE)\n");
    printf("Choose a mode [1/2/3]: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("Idle Mode selected. All sensors are now OFF.\n");
            for (x = 0; x < SENSORS; x++) {
                sensorManager(x, 0); 
            }
            break;

        case 2: 
            printf("Enhanced Security Mode selected.\n");
            printf("Enter bedtime (Military time. Ex. 21:00): ");
            scanf("%s", bedtime);
            printf("Enhanced Security Mode will activate at %s.\n", bedtime);
            for (x = 0; x < SENSORS; x++) {
                sensorManager(x, 1); 
            }
            printf("All sensors are now ACTIVE during bedtime hours.\n");
            break;

        case 3: 
            printf("Maximum Security Mode selected.\n");
            for (x = 0; x < SENSORS; x++) {
                sensorManager(x, 1); 
            }
            printf("All sensors are now FULLY ACTIVE.\n");
            break;

        default:
            printf("Invalid choice. Please select a valid mode [1/2/3]: \n");
            break;
    }

    displaySensorsStatus(); 
    printf("\nWould you like to calibrate another Security Mode? [Y/N]: ");
	scanf(" %c",&continueC);
} while (continueC == 'Y' || continueC == 'y');

	printf("Exiting Sensor Calibration.\n");
}


void displaySensorsStatus() {
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
    char date[10];
    char time[6];
	
	printf("Welcome to Admin simulation!\n\n")
    printf("Enter date today: ");
    scanf("%s", date);
    printf("Enter time today: ");
    scanf("%s", time);
    printf("\nDate: %s\nTime: %s\n", date, time);
	
	sensorCalibration();
    displaySensorsStatus();  
    return 0;
}

