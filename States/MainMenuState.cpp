#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window,  std::map <std::string, int> *supportedKeys)
        :State(window, supportedKeys)
{
    this->init();
}

MainMenuState::~MainMenuState()
{
    for(auto &button : this->buttons) {
        delete button.second;
    }
}

void MainMenuState::init() {
    this->initFonts();
    this->initKeyBinds();
    this->initBackground();
    this->initButtons();
}

void MainMenuState::initBackground() {
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color(107, 17, 35, 200));
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
    this->quit = true;
    std::cout << "Ending main menu state" << std::endl;
}

void MainMenuState::updateInput(const float& deltaTime)
{
    this->checkForQuit();
}

void MainMenuState::updateButtons() {
    for(auto &button : this->buttons) {
        button.second->update(this->mousePositionView);
    }

    // new game
    if(this->buttons["NEW_GAME"]->getIsPressed()) {
        this->endState();
    }

    // check for quit
    if(this->buttons["EXIT_GAME"]->getIsPressed()) {
        this->endState();
    }
}

void MainMenuState::initButtons() {
    this->buttons["NEW_GAME"] = new Button(100, 100, 150, 150,
                                           &this->font, "New Game",
                                       sf::Color(70, 70, 70, 200),
                                       sf::Color(150, 150, 150, 200),
                                       sf::Color(20, 20, 20, 200));
    this->buttons["EXIT_GAME"] = new Button(100, 300, 150, 150,
                                            &this->font, "Exit",
                                           sf::Color(70, 70, 70, 200),
                                           sf::Color(150, 150, 150, 200),
                                           sf::Color(20, 20, 20, 200));
}


void MainMenuState::update(const float& deltaTime)
{
    this->updateMosePositions();
    this->updateInput(deltaTime);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget *target) {
    for(auto &button : this->buttons) {
        button.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    if(!target) target = this->window;
    target->draw(this->background);

    this->renderButtons(target);
}

void MainMenuState::initFonts() {
    this->font.loadFromFile("../Settings/fonts/BLKCHCRY.TTF");
}
