//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_CUSTOMER_H
#define INC_3307_C_CUSTOMER_H

#include "user.h"
#include "Chequing.h"
#include "Savings.h"
#include "Account.h"
#include "MutualFund.h"

class Customer: public User {
public:
    Customer(const string &name, const string &userID);
    int getType();
    int createAccount(int accountType);
    int closeAccount(int accountNum);
    Account* getAccount(int accountNum);
    Account *userAccount;
    vector<Account> accountList;
//    static int nextAccountNum = 1000;
    void printSummary();
};

//array of accounts


#endif //INC_3307_C_CUSTOMER_H
