#include <iostream>
#include "../Header/User.h"
#include "../Header/Manager.h"
#include "../Header/Maintenance.h"
#include "../Header/Logger.h"
#include "../Header/Customer.h"
#include "../Header/Account.h"
#include "../Header/Chequing.h"
#include "../Header/Savings.h"
#include "../Header/Transaction.h"
#include <ctime>

using namespace std;

//constants
const int LOGIN = 1;
const int OPEN_ACCOUNT = 1;
const int CLOSE_ACCOUNT = 2;
const int DEPOSIT = 1;
const int WITHDRAW = 2;
const int TRANSFER = 3;
const int GET_ACCOUNT_BALANCE = 4;
const int PRINT_CUSTOMER_DETAIL = 3;
const int TRACE = 1;
const int ETRANSFER = 5;
const int USER_TRANSFER = 6;
const int PRINT_ACCOUNT_DETAIL_CUSTOMER = 7;
const int LOGOUT = 99;
const int SHUTDOWN = 100;

User *userList[4];

User *validUser(const string userID);
void init();
string getDatetime();

int main() {

    init();
    Logger::init();

    int command;
    string userID = "";
    string customerID = "";
    bool shutdown = false;
    bool logout = false;
    User *currentUser;
    User *selectedUser;
    float depositAmount;
    float withdrawAmount;

    cout << "Starting Ryan's Banking System...\n";

    //allows user to shut down the ATM
    while (!shutdown) {
        cout << "**********************************************************************\n";
        cout << "*                                                                    *\n";
        cout << "******************* Welcome to Western Bank **************************\n";
        cout << "*                                                                    *\n";
        cout << "*                        " + getDatetime() + "                         *\n";
        cout << "**********************************************************************\n";

        cout << "\n\n Please choose an option: \n";

        //alows user to log out
        while (true) {
            //shows correct options depending on user
            if (userID.compare("") == 0) {
                cout << "\n1. Login\nEnter Here: ";
            }
            else {
                if (currentUser->getType() == User::MANAGER) {
                    cout << "1. Open Account\n2. Close Account\n3. Print Account Detail\n99. Logout\n100. Shutdown\nEnter: \n";
                }
                else if (currentUser->getType() == User::CUSTOMER) {
                    cout << "1. Deposit\n2. Withdraw\n3. Transfer\n4. Get Balance\n5. E-Transfer\n6. Transfer to other User\n7. Print account detail\n99. Logout\n100. Shutdown\nEnter: \n";
                }
                else if(currentUser->getType() == User::MAINTENANCE) {
                    cout << "1. Toggle trace\n99. Logout\n100. Shutdown\nEnter: \n";
                }
            }
            cin >> command;

            //all of the possible options that the user can choose
            if (command == LOGIN && userID.compare("") == 0) {
                cout << "Please enter your user ID: ";
                cin >> userID;
                currentUser = validUser(userID);
                if (currentUser == 0) {
                    cout << "No user found with this ID, please try again.\n";
                    userID = "";
                }
                Logger::log("login" + currentUser->getName());
                continue;
            }
            if (command == LOGOUT && userID.compare("") != 0) {
                userID = "";
                Logger::log("logout" + currentUser->getName());
                break;
            }
            if (command == SHUTDOWN) {
                shutdown = true;
                Logger::log("shutdown");

                break;
            }
            if (command == OPEN_ACCOUNT && currentUser->getType() == User::MANAGER && userID.compare("") != 0){
                cout << "Enter the ID of the user you want to create an account for: \n";
                cin >> customerID;
                selectedUser = validUser(customerID);
                if (selectedUser == 0) {
                    cout << "No user found with this ID, please try again.\n";
                    userID = "";
                    continue;
                }

                int accountNum;
                int accountType;
                bool validType = false;

                while (!validType) {
                    cout << "1. Chequing\n2. Savings\n3. Mutual Fund\nEnter Here: ";
                    cin >> accountType;
                    if (accountType == 1 || accountType == 2 || accountType == 3) {
                        validType = true;
                    }
                    else {
                        cout << "Try again.\n";
                    }
                }

                Manager *m = dynamic_cast<Manager *>(currentUser);
                Customer *c = dynamic_cast<Customer *>(selectedUser);
                Logger::log("Create account for " + currentUser->getName() + " by " + selectedUser->getName());
                if (accountType == 1 || accountType == 2) {
                    accountNum = m->Manager::createAccount(c, accountType);
                }
                else {
                    int initialBalance;
                    cout << "Please provide initial investment.\nEnter: \n";
                    cin >> initialBalance;
                    accountNum = m->createInvestmentAccount(c, accountType, initialBalance, getDatetime());
                }
                cout << "The account number is: " << accountNum << "\n\n";
                continue;
            }
            if (command == CLOSE_ACCOUNT && currentUser->getType() == User::MANAGER && userID.compare("") != 0) {
                int accountNum;

                cout << "Enter the ID of the user you want to close an account for: \n";
                cin >> customerID;
                selectedUser = validUser(customerID);
                if (selectedUser == 0) {
                    cout << "No user found with this ID, please try again.\n";
                    userID = "";
                    continue;
                }

                cout << "Enter the account number: \n";
                cin >> accountNum;
                Customer *c = dynamic_cast<Customer *>(selectedUser);
                Manager *m = dynamic_cast<Manager *>(currentUser);

                if (c->getAccount(accountNum)->getBalance() > 0) {
                    cout << "Account can not be closed due to outstanding balance.\n";
                    continue;
                }
                Logger::log("Close account for " + currentUser->getName() + " by " + selectedUser->getName());

                if (m->Manager::closeAccount(c, accountNum) < 0) {
                    cout << "Account number not found\n";
                }
                else {
                    cout << "Account closed.\n";
                }
                continue;
            }
            if (command == DEPOSIT && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                int accountNum;

                cout << "What is your account number? Enter: \n";
                cin >> accountNum;
                cout << "Enter amount you would like to deposit: ";
                cin >> depositAmount;
                Customer *c = dynamic_cast<Customer *>(currentUser);
                Account *customerAccount = c->getAccount(accountNum);
                if (customerAccount == 0) {
                    cout << "Invalid account\n\n";
                    continue;
                }
                Logger::log("deposit: " + c->getName());
                customerAccount->deposit(depositAmount, "CAD", getDatetime());
                cout << "Your current balance is now: $" << c->getAccount(accountNum)->getBalance() << "\n\n";
                continue;

            }
            if (command == WITHDRAW && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                int accountNum;

                cout << "What is your account number? Enter: \n";
                cin >> accountNum;
                cout << "Enter amount you would like to withdraw: ";
                cin >> withdrawAmount;
                Customer *c = dynamic_cast<Customer *>(currentUser);
                Account *customerAccount = c->getAccount(accountNum);
                if (customerAccount == 0) {
                    cout << "Invalid account\n";
                    continue;
                }

                if (customerAccount->getBalance() - withdrawAmount < 0 ) {
                    cout << "You don't have enough money!\n\n";
                    continue;
                }

                Logger::log("withdraw: " + c->getName());
                customerAccount->withdraw(withdrawAmount, "CAD", getDatetime());
                cout << "Your current balance is now: " << c->getAccount(accountNum)->getBalance() << "\n\n";
                continue;
            }
            if (command == TRANSFER && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                int accountNum1;
                int accountNum2;
                int transferAmount;
                cout << "What is your source account number? Enter: \n";
                cin >> accountNum1;
                cout << "What is your destination account number? Enter: \n";
                cin >> accountNum2;
                cout << "How much would you like to transfer? Enter: \n";
                cin >> transferAmount;
                Customer *c = dynamic_cast<Customer *>(currentUser);
                Account *customerAccount1 = c->getAccount(accountNum1);
                Account *customerAccount2 = c->getAccount(accountNum2);
                if (customerAccount1 == 0 || customerAccount2 == 0) {
                    cout << "Invalid account.\n";
                    continue;
                }
                if (customerAccount1->getBalance() - transferAmount < 0 ) {
                    cout << "You don't have enough money!\n";
                    continue;
                }

                Logger::log("transfer: " + c->getName());

                customerAccount1->withdraw(transferAmount, "CAD", getDatetime());
                customerAccount2->deposit(transferAmount, "CAD", getDatetime());
                cout << "The current balance of the first account is: " << c->getAccount(accountNum1)->getBalance() << "\n";
                cout << "The current balance of the second account is: " << c->getAccount(accountNum2)->getBalance() << "\n\n";
                continue;

            }
            if (command == GET_ACCOUNT_BALANCE && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                int accountNum;

                cout << "What is your account number? Enter: \n";
                cin >> accountNum;
                Customer *c = dynamic_cast<Customer *>(currentUser);
                Account *customerAccount = c->getAccount(accountNum);
                if (customerAccount == 0) {
                    cout << "Invalid account\n";
                    continue;
                }
                cout << "Your balance is: " << customerAccount->getBalance() << "\n";
                continue;
            }
            if (command == PRINT_CUSTOMER_DETAIL && currentUser->getType() == User::MANAGER && userID.compare("") != 0) {
                int accountNum;
                Account *customerAccount;

                cout << "Enter the ID of the user you want to check the transaction history or 0 for all: \n";
                cin >> customerID;
                if (customerID.compare("0") != 0) {
                    selectedUser = validUser(customerID);
                    if (selectedUser == 0) {
                        cout << "No user found with this ID, please try again.\n";
                        userID = "";
                        continue;
                    }
                    cout << "Enter the account number: \n";
                    cin >> accountNum;
                    Customer *c = dynamic_cast<Customer *>(selectedUser);
                    c->printSummary();
                }
                else {
                    for (int i = 0; i < 4; i++) {
                        if (userList[i]->getType() == User::CUSTOMER) {
                            Customer *c = dynamic_cast<Customer *>(userList[i]);
                            c->printSummary();
                        }
                    }
                }
                continue;
            }

            if (command == PRINT_ACCOUNT_DETAIL_CUSTOMER && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                int accountNum;
                Account *customerAccount;

                cout << "Enter the account number: \n";
                cin >> accountNum;
                Customer *c = dynamic_cast<Customer *>(currentUser);

                customerAccount = c->getAccount(accountNum);
                if (customerAccount == 0) {
                    cout << "Invalid account number";
                    continue;
                }

                c->getAccount(accountNum)->print();
                continue;
            }
            if (command == TRACE && currentUser->getType() == User::MAINTENANCE && userID.compare("") != 0) {
                if (!Logger::traceStatus()) {
                    Logger::enable();
                    cout << "Trace: ON\n";
                }
                else {
                    Logger::disable();
                    cout << "Trace: OFF\n";
                }
                continue;
            }
            if (command == ETRANSFER && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                string email;
                int amount;
                int accountNum;
                Account *customerAccount;

                cout << "Enter the email you would like to send an E-Transfer to.\nEnter: \n";
                cin >> email;
                cout << "Enter the account number: \n";
                cin >> accountNum;
                cout << "How much would you like to send?\nEnter: \n";
                cin >> amount;
                Customer *c = dynamic_cast<Customer *>(currentUser);

                customerAccount = c->getAccount(accountNum);
                if (customerAccount == 0) {
                    cout << "Invalid account number";
                    continue;
                }

                if (customerAccount->getBalance() - amount < 0 ) {
                    cout << "You don't have enough money!\n\n";
                    continue;
                }
                Logger::log("etransfer: " + c->getName());

                customerAccount->withdraw(amount, "CAD", getDatetime());
                cout << "Your balance is: $" << customerAccount->getBalance() << "\n\n";
                continue;
            }
            if (command == USER_TRANSFER && currentUser->getType() == User::CUSTOMER && userID.compare("") != 0) {
                int accountNum1;
                int accountNum2;
                int amount;
                string customerNum;
                Account *customerAccount1;
                Account *customerAccount2;

                cout << "Enter your account number: \n";
                cin >> accountNum1;
                cout << "Enter the ID of the user you would like to send to: \n";
                cin >> customerNum;
                cout << "Enter this users account number: \n";
                cin >> accountNum2;
                cout << "How much would you like to send?\nEnter: \n";
                cin >> amount;
                selectedUser = validUser(customerNum);
                if (selectedUser == 0) {
                    cout << "No user found with this ID, please try again.\n";
                    userID = "";
                    continue;
                }
                Customer *c1 = dynamic_cast<Customer *>(currentUser);
                Customer *c2 = dynamic_cast<Customer *>(selectedUser);
                customerAccount1 = c1->getAccount(accountNum1);
                customerAccount2 = c2->getAccount(accountNum2);
                if (customerAccount1 == 0 || customerAccount2 == 0) {
                    cout << "Invalid account number\n";
                    continue;
                }
                if (customerAccount1->getBalance() - amount < 0 ) {
                    cout << "You don't have enough money!\n\n";
                    continue;
                }
                Logger::log("user transfer from: " + c1->getName() + " to: " + c2->getName());

                customerAccount1->withdraw(amount, "CAD", getDatetime());
                customerAccount2->deposit(amount, "CAD", getDatetime());
                cout << "Your balance is: $" << customerAccount1->getBalance() << "\n";
                cout << "Transfer Complete.\n\n";
            }

                //command not found
            cout << "Not a valid option!\n";
        }
    }

    Logger::close();
}

//verfies and finds the user
User *validUser(const string userID) {
    for (int i = 0; i < 4; i++) {
        if (userList[i]->getUserID().compare(userID) == 0) {
            return userList[i];
        }
    }
    return 0;
}

//creates test users
void init() {
    userList[0] = new Customer("Ryan", "1");
    userList[1] = new Manager("Jim", "2");
    userList[2] = new Customer("Gimli", "3");
    userList[3] = new Maintenance("Nancy", "4");
}

//returns the date and time
string getDatetime() {
    time_t rawTime;
    struct tm * timeInfo;
    char buffer[80];

    time (&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(buffer,80,"%d-%m-%Y %I:%M:%S",timeInfo);
    string str(buffer);

    return str;
}
