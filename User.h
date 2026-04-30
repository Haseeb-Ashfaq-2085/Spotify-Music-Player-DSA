// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
class User {
private:
    std::string email;
    std::string password;

public:
    User(std::string e, std::string p);
    bool authenticate(std::string e, std::string p);
    ~User();
};

#endif
