#ifndef RPG_GAMESTATE_H
#define RPG_GAMESTATE_H

#include "State.h"
class GameState : public State
{
private:
    Entity player;

    void initKeyBinds();
public:
    ///TODO: supportedKeys use & instead of *

    GameState(sf::RenderWindow* window, std::map <std::string, int> *supportedKeys);
    ~GameState() override;

    void endState();


    void updateInput(const float& deltaTime) override;
    void update(const float& deltaTime) override;
    void render(sf::RenderTarget* target = nullptr) override;
};


#endif //RPG_GAMESTATE_H
