//
// Created by Ryan Dabir on 2016-10-24.
//
// Sub class of Account that allows the user to make an investment account
//

#include "../Header/MutualFund.h"

MutualFund::MutualFund(const int &accountNum, float balance, const string &currency) : Account(accountNum, balance,
                                                                                               currency) {}

void MutualFund::printSummary() {
    cout << "Type: Mutual Fund, Balance: $" << this->getBalance() << ", Currency: CAD";
}