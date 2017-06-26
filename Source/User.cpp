//
// Created by Ryan Dabir on 2016-10-08.
//
// Base class that allows you to get information on the user
//

#include "../Header/User.h"

using namespace std;

string name;
string userID;

User::User(string inputName, string inputUserID) {
    name = inputName;
    userID = inputUserID;
}

string User::getName() {
    return name;
}

string User::getUserID() {
    return userID;
}

void User::setName(const string &name) {
    User::name = name;
}

void User::setUserID(const string &userID) {
    User::userID = userID;
}

int User::getType() {
    return USER;
}

//void User::createAccount(Account tempUserAccount) {
//    userAccount = &tempUserAccount;
//}

//Account* User::getAccount() {
//    return userAccount;
//}

