//
// Created by Ryan Dabir on 2016-10-24.
//

#ifndef INC_3307_C_MUTUALFUND_H
#define INC_3307_C_MUTUALFUND_H

#include "Account.h"

class MutualFund: public Account {
public:
    MutualFund(const int &accountNum, float balance, const string &currency);
    void printSummary();
};


#endif //INC_3307_C_MUTUALFUND_H
