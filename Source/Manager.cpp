//
// Created by Ryan Dabir on 2016-10-08.
//
// Sub class of User that is for opening and closing accounts
//

#include "../Header/Manager.h"

Manager::Manager(const string &name, const string &userID) : User(name, userID) {}

int Manager::getType() {
    return User::MANAGER;
}

int Manager::createAccount(Customer *customer, int accountType ) {

    return (*customer).createAccount(accountType);

}

int Manager::closeAccount(Customer *customer, int accountNum) {
    (*customer).closeAccount(accountNum);
    return 0;
}

int Manager::createInvestmentAccount(Customer *customer, int accountType, float balance, string time) {
    int accountNum = this->createAccount(customer, accountType);
    customer->getAccount(accountNum)->deposit(balance, "CAD", time);
    return accountNum;
}