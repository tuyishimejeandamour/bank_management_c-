#include <iostream>
#include "file.h"
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
void account_screen(Account account);
void delete_account(Account account);
void display_accounts();
void display_account(Account account);
void home_menu();
void home_screen();
Files file;
void withdraw(Account account)
{
	int amount;
	cout << "Enter amount to withdraw: ";
	cin >> amount;
	account.withdraw(amount);
	file.updatefile("./data/account.dat", account, account.getPin());
	cout << "Withdrawal successful" << endl;
}
void deposit(Account account)
{
	int amount;
	cout << "Enter amount to deposit: ";
	cin >> amount;
	account.deposit(amount);
	file.updatefile("./data/account.dat", account, account.getPin());
	cout << "Deposit successful" << endl;
}
void check_balance(Account account)
{
	cout << "Balance: " << account.get_balance() << endl;
}
void change_pin(Account account)
{
	int pin;

	cout << "Enter old pin: ";
	cin >> pin;
	if (account.getPin() == pin)
	{
		cout << "Enter new pin: ";
		cin >> pin;
		account.setPin(pin);
		file.updatefile("./data/account.dat", account, account.getPin());
		cout << "Pin changed successfully" << endl;
	}
	else
	{
		cout << "Wrong pin" << endl;
	}
}
void edit_account()
{
	cout << "Account closed successfully" << endl;
}

void display_accounts()
{
	Account account;
	int i = 0;
	file.Infile.open("./data/account.dat", ios::binary);
	if (!file.Infile.is_open())
	{
		cout << "File not found" << endl;
	}
	else
	{
		file.Infile.seekg(0, ios::beg);
		while (file.Infile.read((char *)&account, sizeof(account)))
		{
			if (!file.Infile.eof())
			{
				cout << "Account no: " << account.getAccountNo() << endl;
				cout << "Name: " << account.getNames() << endl;
				cout << "Balance: " << account.get_balance() << endl;
				cout << "Pin: " << account.getPin() << endl;
				cout << "-----------------------------------------------------" << endl;
			}
			else
			{
				break;
			}
		}
	}

	file.Infile.close();
}
void display_account(Account account)
{
	cout << "Account no: " << account.getAccountNo() << endl;
	cout << "Name: " << account.getNames() << endl;
	cout << "Balance: " << account.get_balance() << endl;
	cout << "Pin: " << account.getPin() << endl;
	cout << "-----------------------------------------------------" << endl;
}
void create_account()
{
	Account account;
	int account_no = account.create_account();
	file.insertfile("./data/account.dat", account);
	cout << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "| Account created successfully" << endl;
	cout << "| Account no: " << account_no << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;
	account_screen(account);
}
void delete_account(Account account)
{
	file.deleteinfile("./data/accounts.dat", account.getPin());
	cout << "Account deleted successfully" << endl;
}
void display_menu()
{
	cout << "1. Deposit             6:view your account" << endl;
	cout << "2. Withdraw            7:view other account" << endl;
	cout << "3. check balance       8:delete account" << endl;
	cout << "4. Change pin          9:go back" << endl;
	cout << "5. edit account" << endl;
}
void account_screen(Account account)
{
	int choice;
	cout << "-----------welcome back----------" << endl;

	do
	{
		cout << endl;
		display_menu();
		cout << "Enter your choice:";
		cin >> choice;
		switch (choice)
		{

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
		case 7:
			display_accounts();
			break;
		case 6:
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
	} while (choice != 9);
}

// end of account_screen)

void open_account(int enteredpin)
{

	Account account = file.loginfile("./data/account.dat", enteredpin);

	if (account.getPin() == enteredpin)
	{
		cout << "Login successful" << endl;
		cout << endl;
		account_screen(account);
	}
	else
	{
		cout << "Login failed" << endl;
	}
}

void home_screen()
{
	int choice, pin;
	cout << "welcome to ibigwi bank" << endl;
	cout << "-----------------------" << endl;

	do
	{
		cout << endl;
		home_menu();
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "----------Create account------------" << endl;
			cout << endl;
			create_account();
			break;
		case 2:
			cout << "enter your pin:" << endl;
			cin >> pin;
			open_account(pin);
			break;
		case 3:
			cout << "----------thank your for using our platform------------" << endl;
			cout << endl;
			break;
		default:
			cout << "invalid option" << endl;
			cout << endl;
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
