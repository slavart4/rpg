#ifndef RPG_GAMESTATE_H
#define RPG_GAMESTATE_H

#include "State.h"
class GameState : public State
{
public:
    GameState(sf::RenderWindow* window, std::map <std::string, int> *supportedKeys);
    ~GameState() override;
    void init();

    void endState();


    void updateInput(const float& deltaTime) override;
    void update(const float& deltaTime) override;
    void render(sf::RenderTarget* target) override;
private:
    Entity player;

    void initKeyBinds();
};


#endif //RPG_GAMESTATE_H
