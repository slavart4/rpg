#include "Mouse.h"

Mouse::Mouse(sf::RenderWindow *window) {
    this->window = window;
}

Mouse::~Mouse() = default;

void Mouse::updateMousePosition() {

    this->mousePositionScreen = sf::Mouse::getPosition();
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}

sf::Vector2i Mouse::getMousePositionScreen() {
    return this->mousePositionScreen;
}

sf::Vector2i Mouse::getMousePositionWindow() {
    return this->mousePositionWindow;
}

sf::Vector2f Mouse::getMousePositionView() {
    return this->mousePositionView;
}


