#include <stdio.h>
#include <stdlib.h>

void admenu(int*);

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
			printf("choice 4");
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

main(){
	int password = 12345;
	adminlogin(&password);
}
