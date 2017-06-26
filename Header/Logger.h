//
// Created by Ryan Dabir on 2016-10-24.
//

#ifndef INC_3307_C_LOGGER_H
#define INC_3307_C_LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


class Logger {
public:
    Logger();
    void static log(string input);
    void static init();
    void static close();
    void static enable();
    void static disable();
    bool static traceStatus();
private:
    bool static trace;
    ofstream static logFile;
};


#endif //INC_3307_C_LOGGER_H
