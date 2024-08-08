#ifndef RPG_MAINMENUSTATE_H
#define RPG_MAINMENUSTATE_H

#include "GameState.h"
#include "../Forms/Button.h"

class MainMenuState : public State {
private:
    //TODO: Add fonts config
    void initFonts();
    void initKeyBinds() override;

    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button *> buttons;
public:
    MainMenuState(sf::RenderWindow* window, std::map <std::string, int> *supportedKeys);
    ~MainMenuState() override;

    void init();
    void initBackground();
    void initButtons();

    void endState() override;

    void updateInput(const float& deltaTime) override;
    void updateButtons();
    void update(const float& deltaTime) override;

    void renderButtons(sf::RenderTarget* target);
    void render(sf::RenderTarget* target) override;
};


#endif //RPG_MAINMENUSTATE_H
