//
// Created by Ryan Dabir on 2016-10-08.
//
// Class that allows you to record each transaction
//

#include "../Header/Transaction.h"

Transaction::Transaction(string inputDate, string inputType, float inputAmount, string inputCurrency){
    date = inputDate;
    type = inputType;
    amount = inputAmount;
    currency = inputCurrency;
}

string Transaction::getDate() const {
    return date;
}

const string &Transaction::getType() const {
    return type;
}

float Transaction::getAmount() const {
    return amount;
}

const string &Transaction::getCurrency() const {
    return currency;
}

void Transaction::print() {
    cout << "Amount: "<< amount << "\n";
    cout << "Type: " << type << "\n";
    cout << "Currency: "<< currency << "\n";
    cout << "Date: " << date << "\n\n";
}