#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window,  std::map <std::string, int> *supportedKeys)
        :State(window, supportedKeys)
{
    this->init();
}

MainMenuState::~MainMenuState()
{

}

void MainMenuState::init() {
    this->initKeyBinds();
    this->initBackground();
}

void MainMenuState::initBackground() {
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Magenta);
}


void MainMenuState::initKeyBinds()
{
    this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
}

void MainMenuState::endState()
{
    std::cout << "Ending main menu state" << std::endl;
}

void MainMenuState::updateInput(const float& deltaTime)
{
    this->checkForQuit();
}

void MainMenuState::update(const float& deltaTime)
{
    this->updateInput(deltaTime);
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target) target = this->window;
    target->draw(this->background);
}