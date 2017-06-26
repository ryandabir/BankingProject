cmake_minimum_required(VERSION 3.6)
project(3307_c__)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Source/main.cpp Source/User.cpp Header/User.h Source/Manager.cpp Header/Manager.h Source/Customer.cpp Header/Customer.h Source/Account.cpp Header/Account.h Source/Chequing.cpp Header/Chequing.h Source/Savings.cpp Header/Savings.h Source/Transaction.cpp Header/Transaction.h Source/Maintenance.cpp Header/Maintenance.h Source/Logger.cpp Header/Logger.h Source/MutualFund.cpp Header/MutualFund.h)
add_executable(3307_c__ ${SOURCE_FILES})