#include<iostream>
#include"file.h"
using namespace std;
// functions to handle operation of user account
void deposit(int, int);
void withdraw(int, int);
void check_balance(int);
void check_pin(int);
void change_pin(int, int);
void close_account();
void open_account(int pin);
void display_menu();

// functions to handle operation of bank
void create_account();
void account_screen(bool &loggedin);
void delete_account(int);
void display_accounts();
void display_account(int);
void home_menu();
void home_screen();
Files file;
void account_screen(int pin){
int choice;
cout <<"-----------welcome to bank----------" << endl;
display_menu();
cin >> choice;
do{

switch(choice){

	case 1:
		deposit(pin, 0);
		break;
	case 2:
		withdraw(pin, 0);
		break;
	case 3:
		check_balance(pin);
		break;
	case 4:
		change_pin(pin, 0);
		break;
	case 5:
		close_account();
		break;
	case 6:
		display_accounts();
		break;
	case 7:
		display_account(pin);
		break;
	case 8:
		delete_account(pin);
		break;
	case 9:
		home_screen();
		break;
	default:
		cout << "PLEASE INSERT CORRECT CHOICE" << endl;
		break;
}
}while(choice != 9);
}	

// end of account_screen)	


void create_account(){

}
void open_account(int enteredpin){
	int pin = 0;
	pin = file.loginfile("./data/account.dat", enteredpin);
	if (pin == 0)
	{
		cout << "invalid pin" << endl;
		return;
	}else
	{
		account_screen(pin);	
	}
}

void home_screen()
{
	int choice,pin;
	cout << "welcome to ibigwi bank" << endl;
	cout << "-----------------------" << endl;
	home_menu();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Create account" << endl;
			create_account();
			break;
		case 2:
			cout << "enter your pin:" << endl;
			cin >> pin;
			open_account(pin);
			break;
		default:
			cout << "Invalid operation" << endl;
			break;
		}
	} while (choice != 3);
}
void home_menu()
{
	cout << "1. create account" << endl;
	cout << "2. open account " << endl;
	cout << "3. quit" << endl;
	cout << "Enter your choice: ";
}
void display_menu()
{
	cout << "1. Deposit        " << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Balance" << endl;
	cout << "4. delete account" << endl;
	cout << "5. Quit" << endl;
	cout << "Enter your choice: ";
}