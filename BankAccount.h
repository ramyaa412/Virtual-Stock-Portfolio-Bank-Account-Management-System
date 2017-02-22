#include<iostream>
#include<fstream> 
#include<string>
#include<time.h>

using namespace std;
#include "Account.h"

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

// Class Bank account derived from base class Account.
class BankAccount : public Account
{
private:
	
	ofstream myfile1;
	ifstream myReadFile;

	ifstream balancefile;
	ofstream write_in_balancefile;

	string line1;

	double deposit_tempval;
	double withdraw_tempval;

public:
	BankAccount();             // consructor
	~BankAccount();            // destructor
	void view_Balance();            // view cash balance
	void deposit_Cash(double);      // deposit cash
	void withdraw_cash(double);      // withdraw cash
	virtual void printtransaction();   // print history
	virtual double getCashBalance();  // get cash balance
	virtual void setCashBalance();    // set cash balance
};

#endif
