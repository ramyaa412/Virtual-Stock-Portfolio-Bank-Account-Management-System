#ifndef ACCOUNT_H
#define ACCOUNT_H

// base class - Account
class Account
{
protected:
	// Data member accessed from both StockAccount and BankAccount classes
	double CashBalance;

public:
	// decalaring  virtual
	virtual void printtransaction() = 0;

	// getting and setting cash balance.
	virtual double getCashBalance() = 0;
	virtual void setCashBalance() = 0;
};

#endif
