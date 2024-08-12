#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, Mouse *mouse, std::map <std::string, int> *supportedKeys)
        :State(window, mouse, supportedKeys)
{
    std::cout << "GameState" << std::endl;
    this->init();
}

GameState::~GameState()
{
    std::cout << "~GameState" << std::endl;
}

void GameState::init() {
    this->initKeyBinds();
}

void GameState::initKeyBinds()
{
    this->keyBinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keyBinds["MOVE_UP"] = this->supportedKeys->at("W");
    this->keyBinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keyBinds["MOVE_DOWN"] = this->supportedKeys->at("S");
    this->keyBinds["MOVE_RIGHT"] = this->supportedKeys->at("D");
}

void GameState::endState()
{
    std::cout << "Ending game state" << std::endl;
}

void GameState::updateInput(const float& deltaTime)
{
    this->checkForQuit();

    // Update player input
    ///TODO: use std::map< std::string, sf::Keyboard::Key > to get rid of casting int to sf::Keyboard::Key

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_UP"))))
        this->player.move(deltaTime, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_LEFT"))))
        this->player.move(deltaTime, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_DOWN"))))
        this->player.move(deltaTime, 0.f, 1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds.at("MOVE_RIGHT"))))
        this->player.move(deltaTime, 1.f, 0.f);
}

void GameState::update(const float& deltaTime)
{
    this->updateMousePositions();
    this->updateInput(deltaTime);
    this->player.update(deltaTime);
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target) target = this->window;
    this->player.render(target);
}