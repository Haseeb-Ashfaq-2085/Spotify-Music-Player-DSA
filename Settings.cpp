// Settings.cpp
#include "Settings.h"
#include <iostream>

Settings* Settings::instance = nullptr;

Settings* Settings::getInstance() {
    if (instance == nullptr) {
        instance = new Settings();
    }
    return instance;
}

void Settings::displaySettings() {
    std::cout << "Settings applied!" << std::endl;
}
