#include <stdio.h>

void password();
void menu();
void adminSetup();
int numInput(char a[]);

int numInput(char a[]){
	int x;
	printf("Enter your %s: ",a);
	scanf("%d", &x);
	return x;
}

void adminSetup(){
	char name[20], street[20], ans, ans2;
	int block, lot, pnumber=0;
	printf("-------------------");
	do{
		printf("\nPlease input your personal information:");
		
		printf("\nEnter your name: ");
		scanf("%s", name);
		
		block = numInput("block number");
		lot = numInput("lot number");
		
		printf("Enter your street: ");
		scanf("%s", street);
		
		pnumber = numInput("phone number");
		
		
		printf("\nYou live in BLOCK %d, LOT %d, at %s STREET.\nContact no: %d\nAre the details correct? [Y/N]: ",block,lot,street,pnumber);
		scanf(" %c", &ans);
		
		if (ans != 'Y' && ans != 'N')
			printf("Invalid input!");
	}while(ans=='N' || ans=='n'); 
	
	if(ans=='Y'||ans=='y')
		do{
			printf("Back to Menu? [Y/N]:");
			scanf(" %c", &ans2);
		}while(ans2=='N' || ans2 == 'n');
			if (ans2=='Y'|| ans2=='y')
				menu();

}

void password(){
	int password=12345,Input1;
	printf("Welcome, Admin!");
	do{
		printf("\nInput 5 digit password:\n");
		scanf("%d",&Input1);
		if (Input1!=password)
			printf("Incorrect password! Try again.\n");
	}while(Input1!=password);
	
	if(Input1==password)
		menu();
}

void menu() {
	int choice;
	printf("---------------------");
	do{
		printf("\nSECURITY SYSTEM MENU\n\n1. User Profile\n2. Reports\n3. Create Guest Account\n4. Sensor Control Panel\n5. Logout\n[1/2/3/4/5]: ");
		scanf("%d",&choice);
		if(choice<1 || choice>5)
			printf("Invalid choice. Please try again.");
	}while(choice<1 || choice>5);
	
	switch(choice){
		case 1: 
			adminSetup(); break;
		case 2:
			printf("choice 2"); break;
		case 3:
			printf("choice 3");break;
		case 4:
			printf("choice 4");break;
		case 5:
			printf("Exiting the program...\n");
			password();
	
	}
}



main(){
	password();
}
