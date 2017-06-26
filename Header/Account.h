//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_ACCOUNT_H
#define INC_3307_C_ACCOUNT_H

#include <iostream>
#include "Transaction.h"
#include "Logger.h"

using namespace std;

class Account {
public:
    Account(int accountNum, float balance, string currency);
    void deposit(float amount, string currency, string time);
    void withdraw(float amount, string currency, string time);
    float getBalance();
    int getAccountNum();
    static int const CHEQUING_ACCOUNT = 1;
    static int const SAVINGS_ACCOUNT = 2;
    static int const MUTUAL_FUND_ACCOUNT = 3;

    static int nextAccountNum;
    void print();
    virtual void printSummary();

private:
    int accountNum;
    float balance;
    string currency;
    Transaction *transactionList[10];
    int transactionCounter = 0;
};

#endif //INC_3307_C_ACCOUNT_H
