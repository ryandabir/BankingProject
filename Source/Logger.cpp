//
// Created by Ryan Dabir on 2016-10-24.
//
// Writes information to text file
//

#include "../Header/Logger.h"

bool Logger::trace = false;
ofstream Logger::logFile;

Logger::Logger() {
}

void Logger::init()
{
    logFile.open("data.txt");
    trace = false;
}

void Logger::close()
{
    logFile.close();
}

void Logger::log(string input) {
    if (trace) {
        logFile << input << "\n";
    }
}

void Logger::enable() {
    trace = true;
}

void Logger::disable() {
    trace = false;
}

bool Logger::traceStatus() {
    return trace;
}