#include<iostream>
using namespace std;
class Account
{
private:
     int account_no;
	 int pin;
	 int deposits;
	 char names[50];
	
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
	int create_account();
	
	
};

Account::Account(){

}

int Account::create_account()
{
	account_no = rand()%1000+1000;
	cout<<"Enter pin: ";
	cin>>pin;
	cout<<"Enter name: ";
	cin.ignore();
	cin.getline(names,50);
	cout<<"Enter initial deposit: ";
	cin>>deposits;

	return account_no;
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
	if (this->pin > 0)
	{
        return true;	/* code */
	}
	return false;

	
}

