#include <stdio.h>
#define SENSORS 5

int sensorStatus[SENSORS];  

void sensorManager(int sensorNum, int activity);
void displaySensorsStatus();

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
    int x;
    int activity;
    char AllSensors;
    
    printf("SENSOR CONTROL PANEL\n\n");
    printf("Welcome to the Sensor Control Panel!\n");
    printf("Options:\n1. Sensor Setup\n2. Sensor Calibration\nChoose [1/2]: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1: { 
            printf("\nSENSOR SETUP\n\n");
            printf("Hello Admin. Welcome to the Sensor Setup!\n");
            
            
			for (x = 0; x < SENSORS; x++) {
        	sensorStatus[x] = 0;
    		}
    		
    		printf("Do you want to activate all sensors? [Y/N]: ");
    		scanf(" %c",&AllSensors);
    		
    		if (AllSensors == 'Y' || AllSensors == 'y'){
    			for (x = 0; x < SENSORS; x++) {
    				sensorManager(x,1);
				}
			} else {
				printf("Do you want to deactivate all sensors? [Y/N]: ");
				scanf(" %c",&AllSensors);
				
				if (AllSensors == 'Y' || AllSensors == 'y'){
					for (x = 0; x < SENSORS; x++) {
						sensorManager(x,0);
					}
				} else {
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
			displaySensorsStatus();
			break;	
			}
            default: 
            printf("Invalid choice.\n");
        }
        }
/*        case 2: { 
            printf("\nSENSOR CALIBRATION\n");
            break;
        }
        default:
            printf("\nInvalid choice!\n");
            break;
    }*/
    
   


