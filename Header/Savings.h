//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_SAVINGS_H
#define INC_3307_C_SAVINGS_H


#include "Account.h"

class Savings: public Account{
public:
    Savings(const int &accountNum, float balance, const string &currency);
    void printSummary();
};


#endif //INC_3307_C_SAVINGS_H
