#include <iostream>
#include <fstream>
#include "account.h"
using namespace std;
class Files
{
private:

	/* data */
public:
	ifstream Infile;
	fstream File;
	ofstream infile;
	Account loginfile(string filepath, int key);
	void updatefile(string filepath, Account account, int key);
	void insertfile(string filepath, Account value);
	void deleteinfile(string filepath, int key);
	Files(/* args */);
};

Files::Files()
{
}

// search in file using key word
Account  Files::loginfile(string filepath, int key)
{    Account account;
     Infile.open(filepath,ios::binary);
	 if (!Infile)
	 {
		cout<<"error occured when openning the file"<<endl;
		return account;
	 }
	 
	 Infile.seekg(0, ios::beg);
	 while(Infile.read(reinterpret_cast<char*> (&account), sizeof(Account)))
	 { 
		 if(account.getPin() == key)
		 {
			 return account;
		 }
	 }	
	 Infile.close();
	return account;		
}

// function which search key word in file
void Files::updatefile(string filepath, Account account, int key)
{
	bool found = false;
	File.open(filepath, ios::binary | ios::in | ios::out);
	if (!File.is_open())
	{
		cout << "file  could not be open " << endl;
		return;
	}
	while (!File.eof() && !found)
	{
		File.read((char *)&account, sizeof(account));
		if (account.getPin() == key)
		{
			found = true;
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*>(&account), sizeof(account));
			cout << "account updated" << endl;
			found = true;
		}
	}
	File.close();
	if (!found)
	{
		cout << "account not found" << endl;
	}
}


void Files::insertfile(string filepath, Account value)
{
	infile.open(filepath, ios::binary | ios::app);
	infile.write((char *)&value, sizeof(value));
	infile.close();
}
void Files::deleteinfile(string filepath, int key){
	Account account;
	File.open(filepath, ios::binary | ios::in | ios::out);
	if (!File.is_open())
	{
		cout << "file  could not be open " << endl;
		File.close();
		return;
	}
	infile.open("./data/temp.dat", ios::binary | ios::app);
	File.seekg(0, ios::beg);
	while (File.read((char *)&account, sizeof(account)))
	{
		if (account.getPin() != key)
		{
			infile.write((char *)&account, sizeof(account));
		}
	}	
	
	File.close();
	infile.close();
	remove(filepath.c_str());	
	rename("./data/temp.dat", filepath.c_str());
	
}