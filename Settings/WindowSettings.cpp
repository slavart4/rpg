#include "WindowSettings.h"

WindowSettings::WindowSettings() {
    this->init();
}

WindowSettings::~WindowSettings() = default;

void WindowSettings::init() {
    this->setSettingsFilePath();
    this->fillData();
}

void WindowSettings::setSettingsFilePath() {
    this->settingFilePath = "windowSettings.json";
}

nlohmann::json WindowSettings::readData() {
    return this->jsonData;
}

void WindowSettings::fillData() {
    std::ifstream settingsFile;
    settingsFile.open("../Settings/settingsFiles/" + this->settingFilePath);

    try {
        settingsFile >> this->jsonData;
    } catch (std::exception& e) {
        std::cout << "WindowSettings parse error " << e.what() << std::endl;
        exit(50);
    }
}

//// setters
//
//void WindowSettings::setWindowWidth(unsigned int width) {
//    if(width) this->jsonData["windowWidth"] = width;
//}
//
//void WindowSettings::setWindowHigh(unsigned int high) {
//    if(high) this->jsonData["windowHigh"] = high;
//}
//
//void WindowSettings::setFramerateLimit(unsigned int limit) {
//    if(limit) this->jsonData["framerateLimit"] = limit;
//}
//
//void WindowSettings::setVerticalSyncEnabled(bool enabled) {
//    this->jsonData["verticalSyncEnabled"] = enabled;
//}
//
//// getters
//
//unsigned int WindowSettings::getWindowWidth() const {
//    return this->jsonData["windowWidth"];
//}
//
//unsigned int WindowSettings::getWindowHigh() const {
//    return this->jsonData["windowHigh"];
//}
//
//unsigned int WindowSettings::getFramerateLimit() const {
//    return this->jsonData["framerateLimit"];
//}
//
//bool WindowSettings::getVerticalSyncEnabled() const {
//    return this->jsonData["verticalSyncEnabled"];
//}
