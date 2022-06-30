#include <iostream>
#include <fstream>
#include "account.h"
using namespace std;
class Files
{
private:
	ifstream Infile;
	fstream File;
	ofstream infile;
	/* data */
public:
	int loginfile(string filepath, int key);
	void updatefile(string filepath, Account account, int key);
	void insertfile(string filepath, Account value);
	void deleteinfile(string filepath, string key);
	Files(/* args */);
};

Files::Files()
{
}

// search in file using key word
int Files::loginfile(string filepath, int key)
{    Account account;
     Infile.open(filepath,ios::binary);
	 Infile.seekg(0, ios::beg);
	 while(Infile.read((char*)&account, sizeof(account)))
	 {
		 if(account.getPin() == key)
		 {
			 return account.getPin();
		 }
	 }	
	return 0;
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
			File.write((char *)&account, sizeof(account));
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
