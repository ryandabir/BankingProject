//
// Created by Ryan Dabir on 2016-10-08.
//

#ifndef INC_3307_C_TRANSACTION_H
#define INC_3307_C_TRANSACTION_H

#include <ctime>
#include <iostream>
using namespace std;


class Transaction {
    private:
        string date;
        string type;
        float amount;
        string currency;
    public:
        Transaction(string inputDate, string inputType, float inputAmount, string inputCurrency);
        string getDate() const;
        const string &getType() const;
        float getAmount() const;
        const string &getCurrency() const;
        void print();

};


#endif //INC_3307_C_TRANSACTION_H
