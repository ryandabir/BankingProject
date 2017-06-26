//
// Created by Ryan Dabir on 2016-10-08.
//
// Class that tracks the accounts for each customer
//

#include <sstream>
#include "../Header/Customer.h"

Customer::Customer(const string &name, const string &userID) : User(name, userID) {
    accountList.reserve(100);
}

int Customer::getType() {
    return User::CUSTOMER;
}

int Customer::createAccount(int accountType)
{

    if (accountList.size() >= 10) {
        cout << "You have too many accounts!";
        return 0;
    }

    int accountNum = Account::nextAccountNum++;

    if (accountType == Account::CHEQUING_ACCOUNT) {

        Account *newAccount = new Chequing(accountNum, 0, "CAD");

        accountList.push_back(*newAccount);

        userAccount = newAccount;
        ostringstream ss;
        ss << newAccount->getAccountNum();
        Logger::log("   Chequing Account, Account Number: " + ss.str());
        return newAccount->getAccountNum();
    }
    else if (accountType == Account::SAVINGS_ACCOUNT) {

        Account *newAccount = new Savings(accountNum, 0, "CAD");

        accountList.push_back(*newAccount);

        userAccount = newAccount;
        ostringstream ss;
        ss << newAccount->getAccountNum();
        Logger::log("   Savings Account, Account Number: " + ss.str());
        return newAccount->getAccountNum();
    }
    else if (accountType == Account::MUTUAL_FUND_ACCOUNT) {

        Account *newAccount = new MutualFund(accountNum, 0, "CAD");

        accountList.push_back(*newAccount);

        userAccount = newAccount;
        ostringstream ss;
        ss << newAccount->getAccountNum();
        Logger::log("   Mutual Fund Account, Account Number: " + ss.str());
        return newAccount->getAccountNum();
    }
    return 0;
}

int Customer::closeAccount(int accountNum) {
    vector<Account>::iterator it = accountList.begin();
    for (;it != accountList.end();it++) {
        if (it->getAccountNum() == accountNum) {
            ostringstream ss;
            ss << it->getAccountNum();
            Logger::log("   Closing account, Account Number: " + ss.str());
            accountList.erase(it);
            return 0;
        }
    }
    return -1;
}

Account* Customer::getAccount(int accountNum) {
    for (int i = 0; i < accountList.size(); i++) {
        if (accountList[i].getAccountNum() == accountNum) {
            return &accountList[i];
        }
    }
    return 0;
}

void Customer::printSummary() {
    float total = 0;
    cout << "User ID: " << this->getUserID() << ", User name: "  << this->getName() << "\n";
    for (int i = 0; i < accountList.size(); i++) {
        accountList[i].printSummary();
        total += accountList[i].getBalance();
    }
    cout << "\nTotal: " << total << "\n";
}