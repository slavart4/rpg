#include "State.h"

State::State(sf::RenderWindow* window, std::map <std::string, int> *supportedKeys)
{
    this->supportedKeys = supportedKeys;
    this->window = window;
    this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
    return this->quit;
}

void State::checkForQuit()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["CLOSE"])))
    {
        this->quit = true;
    }
}

void State::updateMosePositions() {
    this->mousePositionScreen = sf::Mouse::getPosition();
    this->mousePositionWindow = sf::Mouse::getPosition(*this->window);
    this->mousePositionView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
