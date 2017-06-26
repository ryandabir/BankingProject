//
// Created by Ryan Dabir on 2016-10-08.
//
// Sub class of accounts that allows the user to create a savings account
//

#include "../Header/Savings.h"

Savings::Savings(const int &accountNum, float balance, const string &currency) : Account(accountNum, balance,
                                                                                            currency) {}

void Savings::printSummary() {
    cout << "Type: Savings, Balance: $" << this->getBalance() << ", Currency: CAD";
}