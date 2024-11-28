#include <stdio.h>
#include <stdlib.h>

//admin 
void admenu(int*);

//sensors
#define SENSORS 5
int sensorStatus[SENSORS];  
void sensorManager(int sensorNum, int activity);
void sensorCalibration();
void sensorControlPanel();
void displaySensorsStatus();
void sensorSetup();

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
		
		if (ans != 'Y' && ans != 'N' && ans != 'y' && ans != 'n')
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
			printf("Create account goes here.");
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

void sensorControlPanel() {
    int choice;
    char continueS;
    printf("\n\nSENSOR CONTROL PANEL\n\n");
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

	printf("Exiting...\n");
}

int main(){
	int password = 12345;
	adminlogin(&password);
	
}
