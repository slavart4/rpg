#ifndef RPG_MOUSE_H
#define RPG_MOUSE_H

#include "../constants.h"

class Mouse {
public:
    Mouse(sf::RenderWindow *window);
    ~Mouse();

    void updateMousePosition();

    sf::Vector2i getMousePositionScreen();
    sf::Vector2i getMousePositionWindow();
    sf::Vector2f getMousePositionView();
private:
    sf::RenderWindow *window;

    sf::Vector2i mousePositionScreen;
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;
};


#endif //RPG_MOUSE_H
