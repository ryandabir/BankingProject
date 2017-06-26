//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_MANAGER_H
#define INC_3307_C_MANAGER_H

#include "user.h"
#include "customer.h"

class Manager: public User {
public:
    Manager(const string &name, const string &userID);
    int getType();
    int createAccount(Customer *customer, int accountType);
    int closeAccount(Customer *customer, int accountNum);
    int createInvestmentAccount(Customer *customer, int accountType, float balance, string time);
};


#endif //INC_3307_C_MANAGER_H
