#include <stdio.h>
#include <stdlib.h>

//admin 
void admenu(int*);

//sensors
#define SENSORS 5 
void sensorManager(int sensorStatus[SENSORS], int sensorNum, int activity);
void sensorCalibration(int sensorStatus[SENSORS]);
void displaySensorsStatus(int sensorStatus[SENSORS]);
void sensorSetup(int sensorStatus[SENSORS]);
void panicButton();
void manualDisarm(int sensorStatus[SENSORS]);
void sensorControlPanel();

int numInput(char a[]){
	int x;
	printf("Enter your %s: ",a);
	scanf("%d", &x);
	return x;
}



void userprofile(int *password){
	char name[20], street[20], pnumber[20], ans, ans2;
	int block, lot;
	printf("--------------------");
	do{
		printf("\nPlease input your personal information:");
		printf("\nEnter your username: ");
		scanf("%s", name);
		block = numInput("block number");
		lot = numInput("lot number");
		printf("Enter your street: ");
		scanf("%s", street);
		printf("Enter your phone number +63: ");
		scanf("%s", pnumber);
		
		printf("\nYou live in BLOCK %d, LOT %d, at %s STREET.\nContact no: %s\nAre the details correct? [Y/N]: ",block,lot,street,pnumber);
		scanf(" %c", &ans);
		
		if (ans != 'Y' && ans != 'N')
			printf("Invalid input!");
	}while(ans=='N' || ans=='n'); 
	
	if(ans=='Y'||ans=='y')
		do{
			printf("Details saved.");
			printf(" Back to Menu? [Y/N]:");
			scanf(" %c", &ans2);
		}while(ans2=='N' || ans2 == 'n');
			if (ans2=='Y'|| ans2=='y')
				admenu(password);
				
	//these details must be passed to the reports and 

}

void adminlogin(int *password){
	int Input1;
	int run = 1;
	int choice;
	while (run){
		printf("Welcome, Admin!");
		printf("\n1. Login\n2. Exit\n[1/2]: ");
		scanf("%d", &choice);
		switch(choice){
			case 1: do{
					printf("\nEnter your password: ");
					scanf("%d",&Input1);
					if (Input1 != *password)
						printf("Incorrect password! Try again.\n");
					}while(Input1!=*password);
					if(Input1 == *password)
						admenu(password);
					break;
			case 2: printf("Exiting the program...");
					run = 0;
		}
	}
}

void changepassword(int *password){ //value of password is taken instead of its address
	int oldPass, newPass;
	
	do{
	printf("Enter your old password: ");
	scanf("%d", &oldPass);
		if(oldPass != *password)
			printf("Incorrect password. Please try again.");
	}while(oldPass != *password);
	
	if (oldPass == *password){
		printf("Enter your new password: ");
		scanf("%d", &newPass);
		*password = newPass;
		printf("Your password has been changed. Logging you out...\n");
		
	}
	
}

void admenu(int *password) {
	int choice, choice1;
	printf("---------------------");
	do{
		printf("\nSECURITY SYSTEM MENU\n\n1. User Manual\n2. User Profile\n3. Create account\n4. Sensor Control Panel\n5. Start Admin Simulation\n6. Logout\n[1/2/3/4/5/6]: ");
		scanf("%d",&choice);
		if(choice<1 || choice>6)
			printf("Invalid choice. Please try again.");
	}while(choice<1 || choice>6);
	
	switch(choice){
		case 1: 
			printf("User Manual goes here.");
			break;
		case 2:
			do{
			printf("User Profile\n1. Store username and address\n2. Change password\n[1/2]: ");
			scanf("%d",&choice1);
				if(choice1 != 1 && choice1 !=2)
					printf("Invalid choice. Try again.");
			}while(choice1 != 1 && choice1 != 2);
			switch(choice1){
				case 1: userprofile(password); break;
				case 2: changepassword(password);
			}
			break;
		case 3:
			changepassword(password);
			break;
		case 4:
			sensorControlPanel();
			break;
		case 5:
			printf("choice 5");
			break;
		case 6:
			printf("Logging out...\n");
			adminlogin(password);
			break;
	}

}

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
    int bedtimeHour, bedtimeMinute;
    int isValid = 0;
    char change;

	printf("\nSENSOR CALIBRATION\n");
    printf("This system offers three calibration modes:\n");
    printf("1. Idle Mode (Homeowner is home, all sensors OFF)\n");
    printf("2. Enhanced Security Mode (Residents asleep, based on inputted bedtime)\n");
    printf("3. Maximum Security Mode (Homeowners away, all sensors ACTIVE)\n\n");
    
     do {
        do {
            printf("Enter bedtime (Military time, HH MM)\n");
            printf("Enter Hours: ");
            scanf("%d", &bedtimeHour);
            printf("Enter Minutes: ");
            scanf("%d", &bedtimeMinute); 

            if (bedtimeHour >= 0 && bedtimeHour <= 23 && bedtimeMinute >= 0 && bedtimeMinute <= 59) {
                isValid = 1;  
            } else {
                printf("Invalid time input. Hours must be 0-23 and minutes must be 0-59.\n");
            }
        } while (isValid == 0); 

        printf("Enhanced Security Mode will activate at %02d:%02d.\n", bedtimeHour, bedtimeMinute);

        
        displaySensorsStatus(sensorStatus);

       
        printf("Would you like to change the bedtime? [Y/N]: ");
        scanf(" %c", &change);  

    } while (change == 'Y' || change == 'y'); 
    
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

void sensorControlPanel(int *password) {
    int choice;
    char continueS;
    int sensorStatus[SENSORS] = {0};
    
    printf("---------------------");
    printf("\n\nSENSOR CONTROL PANEL\n");
    printf("Welcome to the Sensor Control Panel!\n");
    
    do {
     	printf("\nOptions:\n");
        printf("1. Sensor Setup\n");
        printf("2. Sensor Calibration\n");
        printf("3. Panic Button\n");
        printf("4. Manual Disarm\n");
        printf("Choose [1/2/3/4]: ");
    	scanf("%d", &choice);
    
    switch (choice) {
        case 1: { 
            	sensorSetup(sensorStatus);
            	displaySensorsStatus(sensorStatus);
            	break;
				}
				
		case 2: {
				sensorCalibration(sensorStatus);
				break;
			}
		case 3: {
			panicButton();
			break;
		}
		case 4:{
			manualDisarm(sensorStatus);
			break;
		}
			
        default: {
            	printf("Invalid choice.\n");
			}   
        }
    printf("\nWould you like to go back to Sensor Setup/Calibration? [Y/N]: ");
	scanf(" %c",&continueS);
} while (continueS == 'Y' || continueS == 'y');

	printf("Exiting...\n");
	admenu(password);
}

int main(){
	int password = 12345;
	adminlogin(&password);
}
