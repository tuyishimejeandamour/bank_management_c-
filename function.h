#include<iostream>
#include"file.h"
using namespace std;
// functions to handle operation of user account
void deposit(Account account);
void withdraw(Account account);
void check_balance(int key);
void change_pin(Account account);
void edit_account();
void open_account(int pin);
void display_menu();

// functions to handle operation of bank
void create_account();
void account_screen(bool &loggedin);
void delete_account(Account account);
void display_accounts();
void display_account(Account account);
void home_menu();
void home_screen();
Files file;
void withdraw(Account account){
	int amount;
	cout << "Enter amount to withdraw: ";
	cin >> amount;
	account.withdraw(amount);
	cout << "Withdrawal successful" << endl;	
}
void deposit(Account account){
	int amount;
	cout << "Enter amount to deposit: ";
	cin >> amount;
	account.deposit(amount);
	cout << "Deposit successful" << endl;
}			
void check_balance(Account account){
	cout << "Balance: " << account.get_balance() << endl;
}
void change_pin(Account account){
	int pin;
	cout << "Enter new pin: ";
	cin >> pin;
	account.setPin(pin);
	cout << "Pin changed successfully" << endl;
}
void edit_account(){
	cout << "Account closed successfully" << endl;
}	

void display_accounts(){
	Account account;
	int i = 0;
	file.Infile.open("./data/account.dat", ios::binary);
	file.Infile.seekg(0, ios::beg);
	while(file.Infile.read((char*)&account, sizeof(account)))
	{
		cout << "Account no: " << account.getAccountNo() << endl;
		cout << "Name: " << account.getNames() << endl;
		cout << "Balance: " << account.get_balance() << endl;
		cout << "Pin: " << account.getPin() << endl;
		cout << "-----------------------------------------------------" << endl;
	}
	file.Infile.close();
}
void display_account(Account account){
	cout << "Account no: " << account.getAccountNo() << endl;
	cout << "Name: " << account.getNames() << endl;
	cout << "Balance: " << account.get_balance() << endl;
	cout << "Pin: " << account.getPin() << endl;
	cout << "-----------------------------------------------------" << endl;
}
void create_account(){
	int pin;
	cout << "Enter pin: ";
	cin >> pin;
	open_account(pin);
}
void delete_account(Account account){
	file.deleteinfile("./data/accounts.dat", account.getPin());
	cout << "Account deleted successfully" << endl;
}
void display_menu(){
	cout << "1. Deposit             6:view your account" << endl;
	cout << "2. Withdraw            7:view other account" << endl;
	cout << "3. check balance       8:delete account" << endl;
	cout << "4. Change pin          9:go back" << endl;
	cout << "5. edit account" << endl;
}														
void account_screen(Account account){
int choice;
cout <<"-----------welcome to bank----------" << endl;
display_menu();
cin >> choice;
do{

switch(choice){

	case 1:
		deposit(account);
		break;
	case 2:
		withdraw(account);
		break;
	case 3:
		check_balance(account);
		break;
	case 4:
	    
		change_pin(account);
		break;
	case 5:
		edit_account();
		break;
	case 6:
		display_accounts();
		break;
	case 7:
		display_account(account);
		break;
	case 8:
		delete_account(account);
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

void open_account(int enteredpin){

	Account account = file.loginfile("./data/account.dat", enteredpin);
	if (account.exist())
	{
		cout << "invalid pin" << endl;
		return;
	}else
	{
		account_screen(account);	
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
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "\t\t\t\----------Create account------------" << endl;
			cout<< endl;
			cout<< endl;
			create_account();
			break;
		case 2:
			cout << "enter your pin:" << endl;
			cin >> pin;
			open_account(pin);
			break;
		default:
			cout << "invalid option" << endl;
			cout<<endl;
			break;
		}
	} while (choice != 3);
}
void home_menu()
{
	cout << "1. create account" << endl;
	cout << "2. open account " << endl;
	cout << "3. quit" << endl;
}
