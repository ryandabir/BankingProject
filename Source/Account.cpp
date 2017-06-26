//
// Created by Ryan Dabir on 2016-10-08.
//
// Account class that allows you to perform operations such as deposit and withdraw
//

#include <sstream>
#include "../Header/Account.h"

int Account::nextAccountNum = 1000;

Account::Account(int inputAccountNum, float inputBalance, string inputCurrency) {
    accountNum = inputAccountNum;
    balance = inputBalance;
    currency = inputCurrency;
}

//subtracts amount from balance then adds it to the transaction list
void Account::deposit(float amount, string currency, string time) {
    balance += amount;
    transactionList[transactionCounter++] = new Transaction(time, "Debit", amount, currency);
    ostringstream ss;
    ss << amount;
    Logger::log(" " + time + "," + "Debit, " + ss.str() + ", " + currency);
}

//adds amount and records it
void Account::withdraw(float amount, string currency, string time) {
    int input = 1;

    if (balance > 1000 && balance - amount <= 1000) {
        cout << "Warning: Your balance will be under $1000.00 after this transaction, and a fee of $2.00 will be taken. Continue?\n1. Yes\nAny key to exit.\nEnter:\n";
        cin >> input;
    }

    if (balance > 1000 && input != 1) {
        return;
    }
    else if (balance > 1000 && input == 1) {
        balance -= amount + 2;
        transactionList[transactionCounter++] = new Transaction(time, "Credit", amount, currency);
        return;
    }

    balance -= amount;
    transactionList[transactionCounter++] = new Transaction(time, "Credit", amount, currency);

    ostringstream ss;
    ss << amount;
    Logger::log("    " + time + ", " + "Credit, " + ss.str() + ", " + currency);
}

float Account::getBalance() {
    return balance;
}

int Account::getAccountNum() {
    return accountNum;
}

void Account::print() {
    cout << "The balance of this account is: " << balance << "\n\n";

    for (int i = 0; i < transactionCounter; i++) {
        transactionList[i]->print();
    }
}

void Account::printSummary() {
    cout << "Account Number: " << this->getAccountNum() << ", Balance: " << balance;
}