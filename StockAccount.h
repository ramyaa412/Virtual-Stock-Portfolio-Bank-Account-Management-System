#pragma once
#include<iostream>
#include<fstream> 
#include<string>
#include<time.h>
#include<sstream>
#include<utility>
#include<map>
#include "Account.h"
#include "StockNode.h"

using namespace std;


#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

class StockNode;

class StockAccount : public Account
{
private:
	string ticker_symbol;
	int offset;
	int size;
	int random_file_generate;

	int counter2;

	double portfolioval, valArray2[100];
	string timeArr[100];

	int num_of_shares;

	double max_amt, min_amt;

	ifstream myFile, balancefile, portfile, portvalfile;

	string tempp;
	int sharetempp;

	map<string, double> result1, result2;
	map<string, int> portfolio;
	ifstream myfile1, myfile2;
	stringstream ss;
	stringstream sj;
	stringstream sk;

	string line1, line2, symbol1, date1;
	double price1;

	ofstream write_in_balancefile, write_in_userfile, write_to_portfolio;

	StockNode *prev = NULL;
	StockNode *headptr;
	StockNode *tailptr;

public:
	StockAccount();              // constructor
	~StockAccount();             // destructor 
	void dispStockPrice();       // display stock price
	void dispPortfolio();        // display current portfolio
	void buyShares(StockNode *); // buying shares
	void sellShares();           // selling shares
	void viewGraph();        // view portfolio value variation graph
	virtual void printtransaction();     // overriding printtransaction function to print stock history
	bool sortStockList();        // sorting stock list
	void savePortfolio();        // saving portfolio
	void retrievePortfolio();    // retrieve portfolio at the beginning
	virtual double getCashBalance();    // get cash balance
	virtual void setCashBalance();      // setting cash balance
	void savePortfolioVal();     // save the value and transaction time in portfolio value 
	void retrievePortVal();      // retrieve values from portfolio 
};

#endif
