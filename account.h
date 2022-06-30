#include<iostream>
using namespace std;
class Account
{
private:
     int account_no;
	 int pin;
	 int deposits;
	 string names;
	
	/* data */
public:
    int getAccountNo();
	int get_balance();
	void deposit(int amount);
	void withdraw(int amount);
	int getPin();
	string getNames();
	void setPin(int pin);	

	bool exist();
	Account();
	int create_account(int deposit, int account_no, string names);
	
	
};

Account::Account(){

}

int Account::create_account(int deposit,  int account_no, string names)
{
	account_no = account_no;
	deposit = deposit;
	names = names;
	pin = rand()%1000+1000;
	return pin;
}	



int Account::getPin(){
	return pin;
}
int Account::getAccountNo(){
	return account_no;
}
int Account::get_balance(){
	return deposits;
}		
string Account::getNames(){
	return names;
}		
void Account::setPin(int pin){
	this->pin = pin;
}
void Account::deposit(int amount){
	deposits = deposits + amount;
}
void Account::withdraw(int amount){
	deposits = deposits - amount;
}
bool Account::exist(){
	if (this->pin)
	{
        return true;	/* code */
	}
	return false;

	
}

