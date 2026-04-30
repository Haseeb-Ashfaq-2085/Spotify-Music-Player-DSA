// Settings.h
#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
class Settings {
private:
    static Settings* instance;

    Settings() {}

public:
    static Settings* getInstance();
    void displaySettings();
};

#endif
