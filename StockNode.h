#pragma once
#include<iostream>
#include<string>
#include "Account.h"
#include "StockAccount.h"
using namespace std;

#ifndef STOCKNODE_H
#define STOCKNODE_H

class StockNode
{
	friend class StockAccount;

protected:
	StockNode *nextptr;
	StockNode *prevptr;

	//Each node contains no. of shares and stock symbol.
	int numshares;
	double price_per_share;      // price per share at the time of buying
	double temp_price_per_share; // temporary price per share at the time of sorting
	double tempval;              // value of a node = numshares*temp_price_per_share(/price_per_share)
	string symbol;
	string temp_string;

public:
	StockNode()
	{
		this->nextptr = NULL;
		this->prevptr = NULL;
	}
};

#endif
