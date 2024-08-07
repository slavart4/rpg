#ifndef RPG_ISETTINGS_H
#define RPG_ISETTINGS_H

#include <fstream>
#include <stdexcept>
#include <iostream>

#include "include/json.hpp"

class ISettings {
public:
    virtual ~ISettings() = default;

    virtual nlohmann::json readData() = 0;
    virtual void fillData() = 0;

    virtual void setSettingsFilePath() = 0;
};

#endif
