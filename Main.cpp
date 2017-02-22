
#include <iostream>
#include <string>
#include<fstream>
#include<sstream>
#include<utility>
#include "Account.h"
#include "BankAccount.h"
#include "StockAccount.h"
#include "StockNode.h"
#include "CurrTime.h"
using namespace std;

int main()
{
	int choice1 = 0, choice2 = 0, choice3 = 0;
	double depAmount = 0, witAmount = 0;
	bool flag = true;

	BankAccount BkAcc;
	StockAccount *newptr = new StockAccount();
	StockNode *node = NULL;

	currtime ct;

	cout << "\t\tWelcome to the Account Management System!";

	while (choice1 != 3)
	{
		// displaying main options.
		cout << "\n1. Stock Portfolio Account"
			<< "\n2. Bank Account"
			<< "\n3. Exit";

		cout << "\nPlease Select the Account you wish to Access : ";
		cin >> choice1;

		switch (choice1)
		{
		case 1:
			// Stock Account Options
			while (choice2 != 8)
			{
				cout << "\n\nThese transactions are done :";
				ct.calculate();
				cout << "\nStock Portfolio account";
				cout << "\n1. Display the price for a Stock Symbol"
					<< "\n2. Display Current Portfolio"
					<< "\n3. Buy Shares"
					<< "\n4. Sell Shares"
					<< "\n5. View a Graph for the Portfolio Value"
					<< "\n6. View Transaction History"
					<< "\n7. Sort the Stock List"
					<< "\n8. Return to the Previous Menu";
				cout << "\nEnter Your Choice : ";
				cin >> choice2;
				switch (choice2)
				{
				case 1:
					newptr->dispStockPrice();
					break;
				case 2:
					newptr->dispPortfolio();
					break;
				case 3:
					node = new StockNode();
					newptr->buyShares(node);
					break;
				case 4:
					newptr->sellShares();
					break;
				case 5:
					newptr->viewGraph();
					break;
				case 6:
					newptr->printtransaction();
					break;
				case 7:
					flag = newptr->sortStockList();
					if (flag == false)
						cout << "\nList is Empty! Can't Sort!\n";
					else
						cout << "\nStock list sorted!\n";
					break;
				case 8:
					break;
				default:
					cout << "\nEnter Valid Option!";
				}
			}
			choice2 = 0;
			break;

		case 2:
			// Bank account options
			while (choice3 != 5)
			{
				cout << "\nBank Account";
				cout << "\n1. View Account Balance"
					<< "\n2. Deposit Money"
					<< "\n3. Withdraw Money"
					<< "\n4. Print History"
					<< "\n5. Return to Previous Menu";
				cout << "\nEnter Your Choice : ";
				cin >> choice3;
				switch (choice3)
				{
				case 1:
					BkAcc.view_Balance();
					break;
				case 2:
					cout << "\nEnter Amount in $ to be Deposited : ";
					cin >> depAmount;
					BkAcc.deposit_Cash(depAmount);
					break;
				case 3:
					cout << "\nEnter Amount  int $ to be Withdrawn : ";
					cin >> witAmount;
					BkAcc.withdraw_cash(witAmount);
					break;
				case 4:
					BkAcc.printtransaction();
					break;
				case 5:
					break;
				default:
					cout << "\nEnter Valid Option!";
				}
			}
			choice3 = 0;
			break;
		case 3:
			newptr->savePortfolio();    // saving portfolio.
			newptr->savePortfolioVal(); 
		default:
			cout << "\nExit the Program";
		}
	}
}