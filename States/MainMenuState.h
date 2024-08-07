#ifndef RPG_MAINMENUSTATE_H
#define RPG_MAINMENUSTATE_H

#include "GameState.h"
#include "../Input/Button.h"

class MainMenuState : public State {
private:
    //TODO: Add fonts config
    void initFonts();
    void initKeyBinds() override;

    sf::RectangleShape background;
public:
    MainMenuState(sf::RenderWindow* window, std::map <std::string, int> *supportedKeys);
    ~MainMenuState() override;

    void init();
    void initBackground();

    void endState() override;

    void updateInput(const float& deltaTime) override;
    void update(const float& deltaTime) override;
    void render(sf::RenderTarget* target) override;
};


#endif //RPG_MAINMENUSTATE_H
