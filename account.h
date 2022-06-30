#include<iostream>
using namespace std;
class Account
{
private:
     int account_no;
	 int pin;
	 int deposit;
	 string names;
	
	/* data */
public:
    int getAccountNo();
	int getPin();
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
