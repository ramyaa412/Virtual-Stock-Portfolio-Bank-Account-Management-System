#include<iostream>
#include<iomanip>
#include<time.h>  
#include<fstream>  
#include<string>
#include<stdlib.h>
using namespace std;

#include "BankAccount.h"

//constructor
BankAccount::BankAccount()
{
	setCashBalance();
	deposit_tempval = 0;
	withdraw_tempval = 0;
}

// destructor
BankAccount::~BankAccount()
{
	cout << "\nAccount deleted!";
}

//function for viewing balance
void BankAccount::view_Balance()
{
	setCashBalance();
	//display the current cash balance
	cout << "\nCurrent Balance is : " << "$" <<getCashBalance() <<  endl;
}

//function for depositing cash
void BankAccount::deposit_Cash(double depAmount)
{
	deposit_tempval = depAmount;
	//setCashBalance();
	CashBalance = getCashBalance();

	CashBalance = CashBalance + deposit_tempval;
	cout << "\nAmount of $" << deposit_tempval << " is Deposited to the Account\n";

	//generating the current date and time for deposit transaction
	time_t rawtime;
	struct tm timeinfo;
	char buffer[80];
	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
	std::string str(buffer);

	// writing the deposit transaction to bank_transaction_history.txt file
	myfile1.open("bank_transaction_history.txt", ios::app);
	myfile1 << endl << left << setw(30) << "Deposit";
	myfile1 << left << setw(1) << "$";
	myfile1 << left << setw(15) << deposit_tempval;
	myfile1 << right << setw(15) << str;
	myfile1 << right << setw(5) << "$" << CashBalance;
	myfile1.close();

	// writing to a balance file
	write_in_balancefile.open("balancefile.txt", std::ios_base::out);
	write_in_balancefile << CashBalance;
	write_in_balancefile.close();

	//setCashBalance();
}

//withdrawing cash
void BankAccount::withdraw_cash(double witAmount)
{
	withdraw_tempval = witAmount;
	setCashBalance();
	CashBalance = getCashBalance();

	//to check if the cash balance is greater than 0 
	if (CashBalance > 0)
	{
		//check if withdrwal amount is greater than cash balance 
		if (withdraw_tempval > CashBalance)
		{
			cout << "\nBalance is Not Sufficient! Please Check the Balance before Withdrawing!\n"; //withdrawal operation cancelled
			return;
		}

		//withdrawal operation
		else
		{
			CashBalance = CashBalance - withdraw_tempval;
			cout << "\nAmount of $" << withdraw_tempval << " is withdrawn from the Account\n";

			//generating the current date and time for withdrawal transaction
			time_t rawtime;
			struct tm timeinfo;
			char buffer[80];
			time(&rawtime);
			localtime_s(&timeinfo, &rawtime);
			strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", &timeinfo);
			std::string str(buffer);

			// writing withdrawal transaction to bank_transaction_history.txt file
			myfile1.open("bank_transaction_history.txt", ios::app);
			myfile1 << endl << left << setw(30) << "Withdrawal";
			myfile1 << left << setw(1) << "$";
			myfile1 << left << setw(15) << withdraw_tempval;
			myfile1 << right << setw(15) << str;
			myfile1 << right << setw(5) << "$" << CashBalance;
			myfile1.close();

			// writing the same to the balancefile.txt
			write_in_balancefile.open("balancefile.txt", std::ios_base::out);
			write_in_balancefile << CashBalance;
			write_in_balancefile.close();


			return;
		}
	}
	else
	{
		cout << "\nError : The Account Balance is 0$, can't withdraw Anything now!\n";
	}
}

//printing history
void BankAccount::printtransaction()
{
	myReadFile.open("bank_transaction_history.txt", ios::app);
	cout << endl << left << setw(30) << "Activity";
	cout << left << setw(16) << "Amount";
	cout << left << setw(23) << "Date & Time";
	cout << right << setw(5) << "Balance" << endl;
	if (myReadFile.is_open())
	{
		while (!myReadFile.eof())
		{
			while (getline(myReadFile, line1))
				cout << line1 << "\n";
		}
	}
	myReadFile.close();
}

double BankAccount::getCashBalance()
{
	return CashBalance;
}

void BankAccount::setCashBalance()
{
	streampos length;
	ifstream filestr;
	filestr.open("balancefile.txt", ios::binary);     // open your file
	if (filestr.is_open())
	{
		filestr.seekg(0, ios::end);              // place the cursor at the end of the file
		length = filestr.tellg();                // find the position of the cursor
		filestr.close();                         // close your file
	}

	if (!length) // if length is not found, create the file and put 10,000 cash balance into it.
	{
		double putbalance = 10000.00;
		ofstream outputfile;
		outputfile.open("balancefile.txt", ios_base::out);
		outputfile << putbalance;
		outputfile.close();

		// setting the balance of 10,000
		ifstream readbal("balancefile.txt", ios_base::in);
		readbal >> CashBalance;
		readbal.close();
	}
	else
	{
		// else setting balance from existing cash balance file.
		ifstream readbalance("balancefile.txt", ios_base::in);
		readbalance >> CashBalance;
		readbalance.close();
	}
}