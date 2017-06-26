//
// Created by Ryan Dabir on 2016-10-24.
//

#ifndef INC_3307_C_MAINTENANCE_H
#define INC_3307_C_MAINTENANCE_H

#include "User.h"


class Maintenance: public User {
public:
    Maintenance(const string &name, const string &userID);
    int getType();
};


#endif //INC_3307_C_MAINTENANCE_H
