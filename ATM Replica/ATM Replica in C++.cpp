#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct User{
	char userName[100];
	char pin[10];
	float amount;
}u;


//Declaring global variables...
FILE *fp;
char user[50];
char pinCode[10];
int match = 0,count = 6;
const char *askData[4] = {"\n\t\tAdding new users. Please provide following information:\n","\t\tUsername: ","\t\tCreate Pincode: ","\t\tInsert Amount: "};

//Prototypes/Signatures of functions...
void gotoxy(short x, short y);
void homeScreen();
void addUsers();
void logIn();
int updateRecord(User,const char*,int,int);
void listUsers();
void mainMenu(User);
void fastCash(User);
void checkBalance(User);
void withdrawAmount(User);
void depositfund(User);
void transferfund(User);
void adminMenu();

int main(){	
	homeScreen();
	logIn();	
}

void adminMenu(){
	int i;
	LABEL1:
	char arr[] = "Abdul Hadi";
	
	system("cls");
	printf("\n\n\t\tYou must be admin because only admin have access to this feature..\n\n");
	printf("\t\t1 = Create Accounts\n\t\t2 = View all acounts information\n\t\t3 = Main Menu\n\t\t4 = Power off the machine\n\n");
	cout << "\t\tChoice: ";
	cin>>i;
	switch(i){
		case 1:
			system("cls");
			addUsers();
			break;
		case 2:
			system("cls");
			listUsers();
			getch();
			break;
		case 3:
			for(int j=0; arr[j]!='\0';j++)
			{
				u.userName[j] = arr[j];
			}
			mainMenu(u);			
			break; // Not required but writing just in case of satisfaction...
		case 4:
			puts("\n\t\tPowering off system...\n\n");
			exit(0);
			break;
		default:
			puts("\n\t\tInvalid choice...\n\n");
			Sleep(1000);
			goto LABEL1;
			break;
	}
	goto LABEL1;
}

//Defining mainMenu method that will show the menus...
void mainMenu(User p){
	int option;   // Variable for Switch Statement...
	char choice;  // To repeat the main menu (switch statement)...
	
	again:        // label set for the repetition of loop...
	system("cls");// to clear the screen...
	cout << "\n\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
	printf("\t\t\tWelcome back %s to ATM Service \n",p.userName);
	cout << "\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n\n"<<endl;
	cout<<"\t 1) Check Balance \n"<<endl;
	cout<<"\t 2) Fast Cash \n"<<endl;
	cout<<"\t 3) Withdraw Amount \n "<<endl;
	cout<<"\t 4) Deposit Fund \n "<<endl;
	cout<<"\t 5) Transfer Fund \n "<<endl;
	cout<<"\t 6) Exit \n \n"<<endl;
	cout<<"\t Please Select Your Option :\t";
	cin>>option;
	
	switch (option){	// Switch statement for the executions of main menus...
		case 1:
			system("cls");
			checkBalance(p);
			break;
		case 2:
			system("cls");
			fastCash(p);
			break;
		case 3:
			system("cls");
			withdrawAmount(p);
			break;
		case 4:
			system("cls");
			depositfund(p);
			break;
		case 5:
			system("cls");
			transferfund(p);
			break;
		case 6:
			system("cls");
			cout<<"\n\n\t\t Thanks for using Admirals ATM\n\n"<<endl;
			Sleep(2000);
			exit(0);
			break;
		default:
			cout<<"\t\tInvalid choice!\n\n";
			goto again;
	}
	cout<<"\n\n\n\n\t\tDo you have another transaction? ( Y/N ) : ";
	cin>>choice;
	if(choice=='y'||choice=='Y'){ // The repetiion of Swicth statement through goto...
	system("cls");
	goto again;
	}else{
		cout<<"\n\n\t\tThanks for using Admirals ATM\n"<<endl;
		exit(0); // Exiting Program Succesfully...
	}
}
// This Function shows the Current Balance...
void checkBalance(User u1){ 
	system("cls");
	gotoxy(20,10);
	u1.amount = updateRecord(u1,u1.userName,0,0);
	cout<<"Your Current Amount is : "<<u1.amount;
}

void fastCash(User k){
	int i,amounts[9] = {500,1000,1500,2000,3000,5000,10000,20000,40000};
	char c;
	label:
	system("cls");
	printf("\n\n\t\tPlease Select Your Amount\n\n\n\t1. 500\t\t\t\t\t6. 5000\n\n\t2. 1000\t\t\t\t\t7. 10,000\n\n\t3. 1500\t\t\t\t\t8. 20,000\n\n\t4. 2000\t\t\t\t\t9. 40,000\n\n\t5. 3000\t\t\t\t\t0. Main Menu\n\n");
	cout << "\n\t\tChoice: \t";
	cin>>i;
	switch(i){
		case 1:
			if(amounts[0]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = (k,k.userName,amounts[0],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 2:
			if(amounts[1]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[1],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 3:
			if(amounts[2]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[2],0);
				puts("Please collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 4:
			if(amounts[3]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[3],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 5:
			if(amounts[4]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[4],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 6:
			if(amounts[5]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[5],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 7:
			if(amounts[6]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[6],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 8:
			if(amounts[7]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[7],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 9:
			if(amounts[8]>k.amount){
				system("cls");
				puts("\n\t\tNo Sufficient Balance for this transaction...\n\t\tPlease select another amount\n\n");
				Sleep(2000);
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amounts[8],0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(1000);
			}
			break;
		case 0:
			system("cls");
			mainMenu(k);
			break;
		default:
			puts("\t\tInvalid choice... Please try again\n\n");
			Sleep(2000);
			goto label;
			break;
	}
	cout<<"\n\t\tDo you have another transaction? ( Y/N ) : ";
	cin>>c;
	if(c == 'Y' || c == 'y'){
		mainMenu(k);
	}else{
		puts("\t\tThanks for using Admirals ATM\n");
		Sleep(1000);
		exit(0);
	}
}

void withdrawAmount(User k){
	int amount = 0;
	char c;
	system("cls");
	label:
	cout<<"\n\t\t------Welcome to Amount Withdraw Window-----\n\n"<<endl;
	printf("\n\n\t\tEnter an Amount : ");
	cin>>amount;
	if(amount>k.amount){
				system("cls");
				puts("\t\tInsufficient balance... Please enter another amount\n\n");
				goto label;
			}else{
				k.amount = updateRecord(k,k.userName,amount,0);
				puts("\t\tPlease collect your cash!\n");
				Sleep(2000);
			}
	cout<<"\t\tDo you have another transaction? ( Y/N ) : ";
	cin>>c;
	if(c == 'Y' || c == 'y'){
		mainMenu(k);
	}else{
		puts("\t\tThanks for using this Admirals ATM\n");
		Sleep(2000);
		exit(0);
	}
}

void depositfund(User us){
	int deposit;
	char c;
	
	system("cls");
	cout<<"\n\t\t------Welcome to Amount Deposit Window-----\n\n"<<endl;
	cout<<"\t\tEnter amount to deposit : ";
	cin>>deposit;
	us.amount = updateRecord(us,us.userName,0,deposit);
	cout<<"\n\t\tDeposit completed...\n\n"<<endl;
	cout<<"\t\tYour new amount is  "<<us.amount<<endl<<endl;
	cout<<"\t\tDo you have another transaction? ( Y/N ) : ";
	cin>>c;
	if(c == 'Y' || c == 'y'){
		mainMenu(us);
	}else{
		puts("\t\tThanks for using this Admirals ATM\n");
		Sleep(2000);
		exit(0);
	}				
}

void transferfund(User us){
	char name[100],c;
	int amount = 0;
	cout<<"\n\t\t****  Welcome to money transfer window  ***** \n\n"<<endl;
	fflush(stdin);
	cout<<"\t\tReceipt Name : ";
	cin.getline(name,100);
	cout<<"\n\n\t\tAmount to transfer : ";
	cin>>amount;
	while( us.amount < amount ){
	cout<<"\n\n\t\tYou don't have sufficient balance...\n\t\tPlease try another amount... \n\t\tEnter the amount to transfer : ";
	cin>>amount;
	}
	us.amount = updateRecord(us,us.userName,amount,0);
	cout<<"\n\t\tFund transfered succesfully!\n\n\t\tYour current balance is : "<<us.amount;
	cout<<"\n\n\t\tDo you have another transaction? ( Y/N ) : ";
	cin>>c;
	if(c == 'Y' || c == 'y'){
		mainMenu(us);
	}else{
		puts("\n\t\tThanks for using this Admirals ATM\n");
		Sleep(2000);
		exit(0);
	}		
}

void gotoxy(short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void homeScreen(){
	char a[10];
	a[1] = 219 , a[2] = 220; a[3] = 221; a[4] = 222, a[0] = 223;
	
	for(int i=0; i<24; i++){
		for(int j=0; j<80; j++){
			if(i==0){
				if(j==0 || j==79)
				cout << a[1];
				else
				cout << a[0];
			}else if((i==1) || (i==2) || (i==6) || (i==8) || (i==12) || (i==13) || (i==15) || (i>18 && i<23)){
				if(j==0 || j==79)
				cout << a[1];
				else
				cout << " ";
			}else if(i==3){
				if((j==0) || (j==18) || (j==23) || (j==25) || (j==31) || (j==35) ||
					(j==41) || (j==44) || (j==47) || (j==52) || (j==55) || (j==79))
				cout <<a[1];
				else if((j>25 && j<29) || (j>35 && j<39) || (j>41 && j<44) || (j>55 && j<59))
				cout <<a[0];
				else if(j==48)
				cout << "\\";
				else if(j==51)
				cout<<"/";
				else
				cout << " ";
			}else if(i==4){
				if((j==0) || (j==18) || (j==23) || (j==25) || (j==31) || (j==35) ||
					(j==41) || (j==44) || (j==47) || (j==52) || (j==55) || (j==79))
				cout <<a[1];
				else if((j>25 && j<28) || (j>55 && j<59))
				cout <<a[0];
				else if(j==49 || j==21)
				cout << "\\";
				else if(j==50 || j==20)
				cout<<"/";
				else
				cout << " ";
			}else if (i==5){
				if((j==0) || (j==18) || (j==23) || (j==25) || (j==31) || (j==35) ||
					(j==41) || (j==44) || (j==47) || (j==52) || (j==55) || (j==79))
				cout <<a[1];
				else if((j>25 && j<29) || (j>31 && j<34) || (j>35 && j<39) || (j>41 && j<44) || (j>55 && j<59))
				cout <<a[2];
				else if(j==22)
				cout << "\\";
				else if(j==19)
				cout<<"/";
				else
				cout << " ";
			}else if(i==7){
				if(j==0 || j==79)
				cout << a[1];
				else if(j==37)
				cout << "T";
				else if(j==39)
				cout << "O";
				else
				cout << " ";
			}else if(i==9){
				if((j==0) || (j==79))
				cout <<a[1];
				else if(j==42)
				cout << a[4];
				else if(j==47)
				cout << a[3];
				else if(j>36 && j<40)
				cout <<a[2];
				else if(j==33 || j==43)
				cout << "\\";
				else if(j==32 || j==46)
				cout<<"/";
				else
				cout << " ";
			}else if (i==10){
				if((j==0) || (j==38) || (j==79))
				cout <<a[1];
				else if(j>31 && j<34)
				cout <<a[2];
				else if((j==42) || (j==31))
				cout << a[4];
				else if((j==47) || (j==34))
				cout << a[3];
				else if(j==44)
				cout << "\\";
				else if(j==45)
				cout<<"/";
				else
				cout << " ";
			}else if (i==11){
				if((j==0) || (j==38) || (j==79))
				cout <<a[1];
				else if((j==42) || (j==31))
				cout << a[4];
				else if((j==47) || (j==34))
				cout << a[3];
				else
				cout << " ";
			}else if(i==14){
				if(j==0 || j==79)
				cout << a[1];
				else if(j==2)
				cout << "A PROJECT BY:";
				else if (j>2 && j<15)
				continue;
				else
				cout << " ";
			}else if(i==16){
				if((j==0) || (j==24) || (j==26) || (j==38) || (j==53) || (j==59) || (j==79))
				cout <<a[1];
				else if((j==23) || (j==25) || (j>41 && j<44) || (j>59 && j<62))
				cout <<a[0];
				else if((j==29) || (j==41))
				cout << a[4];
				else if((j==34) || (j==44))
				cout << a[3];
				else if(j==19 || j==49 || j==30)
				cout << "\\";
				else if(j==18 || j == 48 || j==33)
				cout<<"/";
				else
				cout << " ";
			}else if(i==17){
				if((j==0) || (j==24) || (j==26) || (j==38) || (j==53) || (j==61) || (j==79))
				cout <<a[1];
				else if((j>17 && j<20) || (j>41 && j<44) || (j>47 && j<50))
				cout <<a[2];
				else if(j>58 && j<61)
				cout << a[0];
				else if((j==17) || (j==29) || (j==41) || (j==47))
				cout << a[4];
				else if((j==20) || (j==34) || (j==44) || (j==50))
				cout << a[3];
				else if(j==31)
				cout << "\\";
				else if(j==32)
				cout<<"/";
				else
				cout << " ";
			}else if(i==18){
				if((j==0) || (j==24) || (j==26) || (j==38) || (j==53) || (j==61) || (j==79))
				cout <<a[1];
				else if((j==23) || (j==25) || (j>53 && j<57) || (j>58 && j<61))
				cout <<a[2];
				else if((j==17) || (j==29) || (j==41) || (j==47))
				cout << a[4];
				else if((j==20) || (j==34) || (j==50))
				cout << a[3];
				else if(j==42 || j==43)
				cout << "\\";
				else
				cout << " ";
			}else if(i==23){
				if(j==0 || j==79)
				cout << a[1];
				else
				cout << a[2];
			}
		}
	}
	gotoxy(25,21);
	cout << "Loading Please Wait..."<<endl;
	gotoxy(25,22);
	for(int i=0; i<22; i++){
		cout << a[1];
		Sleep(100);
	}
	gotoxy(25,21);
	for(int i=0; i<22; i++)
	cout << " ";
	gotoxy(25,22);
	for(int i=0; i<22; i++)
	cout << " ";
	gotoxy(25,21);
	cout << "Press Enter key to continue...";
	char c;
	c = getc(stdin);
	if(c=='|')
	{
		adminMenu();
	}
	system("cls");
	if(c == '|'){
		adminMenu();
	}
}

void addUsers(){
	char choice = 'Y';
	
	if((fp = fopen("Users Information.bin","ab")) == NULL ){
		fp = fopen("Users Information.bin","wb");
	}
	
	cout<<askData[0];
	while(true){
		fflush(stdin);
		cout<<"\n\t\t"<<askData[1];
		cin.getline(u.userName,100);
		fflush(stdin);
		cout<<"\n\t\t"<<askData[2];
		cin.getline(u.pin,10);
		fflush(stdin);
		cout<<"\n\t\t"<<askData[3];
		cin>>u.amount;
		
		fwrite(&u,sizeof(u),1,fp);
		printf("\n\n\t\tDo you want to add another user? ( Y/N ) : ");
        cin>>choice;
        if(choice=='n' || choice=='N'){
            break;
		}    
	}
	fclose(fp);
}

void listUsers(){
	fp=fopen("Users Information.bin","rb");
	if(fp == NULL){
		puts("\n\n\t\tFile not found!\n");
		exit(1);
	}
    printf("\t\tSecret Information of Users:\n");                
	while(fread(&u,sizeof(u),1,fp) == 1){
       	printf("\n\t\tUsername: %s\n\t\tPincode: %s\n\t\tAvailable Balance: %0.2f\n",u.userName,u.pin,u.amount);
    }
    fclose(fp);
}

int updateRecord(User us,const char *userName,int withdraw,int deposite){
	fp=fopen("Users Information.bin","rb+");
	while(fread(&us,sizeof(us),1,fp)==1){	
		if(strcmp(userName,us.userName)==0){
			
			withdraw>0?(us.amount -= withdraw): (us.amount = us.amount);
			deposite>0?(us.amount += deposite): (us.amount = us.amount);
			
			fseek(fp,ftell(fp)-sizeof(us),0);
			fwrite(&us,sizeof(us),1,fp);
			fclose(fp);
			}
	}
	return us.amount;
}
void logIn(){
	cout << "\n\n\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<endl;
	cout << "\t\t\t\tPlease Login"<<endl;
	cout << "\t\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n\n\n\n\n"<<endl;
	
	while(match <= 0){
		if((fp = fopen("Users Information.bin","rb")) == NULL){
			puts("\n\n\t\tCould not connect to the database... Please try again later...\n\n");
			exit(1);
		}
		fflush(stdin);
		cout << "\n\t\tUsername\t:  ";
		cin.getline(user,50);
		while(match <= 0 && fread(&u,sizeof(u),1,fp)){
			if(strcmp(user,u.userName)==0){
				match = 1;
			}	
		}
		if(match <=0)
		puts("\n\n\t\tUsername not found! Please try again.");	
		fclose(fp);
	}
	while(match <= 1){
		if((fp = fopen("Users Information.bin","rb")) == NULL){
			puts("\n\t\tFile not found!\n");
			exit(1);
		}
		if( count <=3 ){
			printf("\n\n\t\tYou seems unlucky, only %d attemps left\n",count);
			if(count == 0){
				puts("\n\n\t\tSystem shutting down, please come back later.");
				Sleep(2000);
				exit(0);
			}
		}
		fflush(stdin);
		cout << "\n\t\tPIN\t\t:  ";
		cin.getline(pinCode,10);
		while(match <= 1 && fread(&u,sizeof(u),1,fp)){
			if(strcmp(pinCode,u.pin)==0 && strcmp(user,u.userName)==0){
				system("cls");
				mainMenu(u);
				match = 2;
			}	
		}
		if(match <=1){
			puts("\n\n\t\tIncorrect Pin, Please try again");
			count--;		
		}
		fclose(fp);
	}
}
