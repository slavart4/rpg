#ifndef RPG_WINDOWSETTINGS_H
#define RPG_WINDOWSETTINGS_H

#include "ISettings.h"

class WindowSettings : public ISettings {
public:
    WindowSettings();
    ~WindowSettings();

    void init();
    void setSettingsFilePath() override;

    nlohmann::json readData() override;
    void fillData() override;

//    // setters
//    void setWindowWidth(unsigned int width);
//    void setWindowHigh(unsigned int high);
//    void setFramerateLimit(unsigned int limit);
//    void setVerticalSyncEnabled(bool enabled);
//
//    //getters
//    unsigned int getWindowWidth() const;
//    unsigned int getWindowHigh() const;
//    unsigned int getFramerateLimit() const;
//    bool getVerticalSyncEnabled() const;
private:
    nlohmann::json jsonData;
    std::string settingFilePath;
};


#endif //RPG_WINDOWSETTINGS_H
