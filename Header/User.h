//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_BANKUSER_H
#define INC_3307_C_BANKUSER_H

#include <iostream>
#include "../Header/Account.h"
#include <vector>

using namespace std;

class User {
private:
    string name;
    string userID;
    Account *userAccount;
public:
    const static int USER = 1;
    const static int CUSTOMER = 2;
    const static int MANAGER = 3;
    const static int MAINTENANCE = 4;
    User(string name, string userID);
    string getName();
    string getUserID();
    void setName(const string &name);
    void setUserID(const string &userID);
    virtual int getType();
    //void createAccount(Account tempUserAccount);
//    Account* getAccount();
};


#endif //INC_3307_C_BANKUSER_H
