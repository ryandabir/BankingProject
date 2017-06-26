//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_CHEQUING_H
#define INC_3307_C_CHEQUING_H


#include "Account.h"

class Chequing: public Account {
public:
    Chequing(const int &accountNum, float balance, const string &currency);
    void printSummary();

};


#endif //INC_3307_C_CHEQUING_H
