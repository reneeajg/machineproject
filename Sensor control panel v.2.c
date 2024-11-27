#include <stdio.h>
#define SENSORS 5

int sensorStatus[SENSORS];  

void sensorManager(int sensorNum, int activity);
void sensorCalibration();
void displaySensorsStatus();
void sensorSetup();

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

void sensorSetup(){
	int x;
	char AllSensors;
	int activity;
	printf("\nSENSOR SETUP\n");
            printf("Hello Admin. Welcome to the Sensor Setup!\n");
            
            
			for (x = 0; x < SENSORS; x++) {
        	sensorStatus[x] = 0;
    		}
    		printf("The security system has 5 programmable sensors.\nYou can choose to ACTIVATE/DEACTIVATE all sensors OR choose to ACTIVATE/DEACTIVATE each specific sensor.\n\n");
    		printf("Do you want to ACTIVATE all sensors? Choose [Y/N]: ");
    		scanf(" %c",&AllSensors);
    		
    		if (AllSensors == 'Y' || AllSensors == 'y'){
    			for (x = 0; x < SENSORS; x++) {
    				sensorManager(x,1);
				}
			} else {
				printf("Do you want to DEACTIVATE all sensors? [Y/N]: ");
				scanf(" %c",&AllSensors);
				
				if (AllSensors == 'Y' || AllSensors == 'y'){
					for (x = 0; x < SENSORS; x++) {
						sensorManager(x,0);
					}
				} else {
					printf("\nChoose which sensors to activate or deactivate  individually\n");
					for (x = 0; x < SENSORS; x++) {
            	printf("\nCurrent Status: Sensor %d ",x);
            	if(sensorStatus[x]==1){
            		printf("ACTIVE\n");
            }	else {
            		printf("INACTIVE\n");
			}
				printf("Choose activity for Sensor %d:\n",x);
				printf("0 - Deactivate\n1 - Activate\nChoose [0/1]: ");
				scanf("%d",&activity);
				
				while(activity != 0 && activity != 1){
				printf("Invalid input. Try again (0 - Deactivate, 1 - Activate): ");
				scanf("%d",&activity);
					}
				
				sensorManager(x,activity);
				}
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
    	printf("Sensor %d: ",x);
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
    printf("SENSOR CONTROL PANEL\n\n");
    printf("Welcome to the Sensor Control Panel!\n");
    
    do {
    printf("Options:\n1. Sensor Setup\n2. Sensor Calibration\nChoose [1/2]: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: { 
            	sensorSetup();
            	displaySensorsStatus();
            	break;
				}
				
		case 2: {
				sensorCalibration();
				break;
			}
            default: {
            	printf("Invalid choice.\n");
			}   
        }
    printf("\nWould you like to go back to Sensor Setup/Calibration? [Y/N]: ");
	scanf(" %c",&continueS);
} while (continueS == 'Y' || continueS == 'y');

	printf("Exiting.");
}
   
    
   


