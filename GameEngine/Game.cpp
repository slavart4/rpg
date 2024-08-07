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

    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }
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
    this->states.push(new MainMenuState(this->window, &this->supportedKeys));
    //this->states.push(new GameState(this->window, &this->supportedKeys));
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

    if (!this->states.empty())
    {
        this->states.top()->update(this->deltaTime);

        if(this->states.top()->getQuit())
        {
            this->states.top()->endState();
            delete this->states.top();
            this->states.pop();
        }
    }
    else
    {
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    // Update items
    if (!this->states.empty()) {
        this->states.top()->render(this->window);
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
