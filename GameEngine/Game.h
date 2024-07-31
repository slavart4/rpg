#ifndef RPG_GAME_H
#define RPG_GAME_H

#include "../States/State.h"
#include "../States/GameState.h"

class Game
{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float deltaTime;

    std::stack<State*> states;
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
