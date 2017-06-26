//
// Created by Ryan Dabir on 2016-10-08.
//
// Sub class of Account
//

#include "../Header/Chequing.h"

Chequing::Chequing(const int &accountNum, float balance, const string &currency) : Account(accountNum, balance,
                                                                                              currency) {}

void Chequing::printSummary() {
    cout << "Type: Chequing, Balance: $" << this->getBalance() << ", Currency: CAD";
}