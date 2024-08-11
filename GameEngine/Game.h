#ifndef RPG_GAME_H
#define RPG_GAME_H

#include "../Settings/WindowSettings.h"
#include "../States/MainMenuState.h"

class Game
{
private:
    StateContext *stateContext;

    ISettings *windowSettings;
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float deltaTime;

    std::map <std::string, int> supportedKeys;

    void initWindow();
    void initStates();
    void initKeys();
public:
    Game();
    virtual ~Game();

    void updateDeltaTime();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};


#endif //RPG_GAME_H
