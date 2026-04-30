// User.cpp
#include "User.h"
#include <iostream>

User::User(std::string e, std::string p) : email(e), password(p) {}

bool User::authenticate(std::string e, std::string p) {
    return (e == email && p == password);
}

User::~User() {
    std::cout << "User object destroyed!" << std::endl;
}
