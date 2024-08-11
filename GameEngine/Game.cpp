#include "Game.h"

Game::Game() {
    this->windowSettings = new WindowSettings();
    this->initWindow();
    this->initKeys();
    this->initStates();
}

Game::~Game() {
    delete this->window;
    delete this->windowSettings;
    delete this->stateContext;
}

void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(this->windowSettings->readData()["windowWidth"],
                                                      this->windowSettings->readData()["windowHigh"]), "SFML RPG!");
    this->window->setFramerateLimit(120);
    this->window->setVerticalSyncEnabled(false);

}

void Game::initKeys() {
    this->supportedKeys["Escape"] = sf::Keyboard::Key::Escape;
    this->supportedKeys["W"] = sf::Keyboard::Key::W;
    this->supportedKeys["A"] = sf::Keyboard::Key::A;
    this->supportedKeys["S"] = sf::Keyboard::Key::S;
    this->supportedKeys["D"] = sf::Keyboard::Key::D;
}


void Game::initStates()
{
    State *mainMenuState = new MainMenuState(this->window, &this->supportedKeys);
    this->stateContext = new StateContext(mainMenuState);
    mainMenuState->set_context(this->stateContext);
}

void Game::updateDeltaTime()
{
    this->deltaTime = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}


void Game::update()
{
    this->updateSFMLEvents();

    if(this->stateContext) {
        this->stateContext->update(this->deltaTime);
    } else {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    // Render items
    if (this->stateContext) {
        this->stateContext->render(this->window);
    }

    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen()) {
        this->updateDeltaTime();
        this->update();
        this->render();
    }
}
