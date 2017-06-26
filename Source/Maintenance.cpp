//
// Created by Ryan Dabir on 2016-10-24.
//
// Sub class of User that is meant for enable trace
//

#include "../Header/Maintenance.h"

Maintenance::Maintenance(const string &name, const string &userID) : User(name, userID) {}

int Maintenance::getType() {
    return User::MAINTENANCE;
}