#ifndef RPG_BUTTON_H
#define RPG_BUTTON_H

#include "../constants.h"

enum buttonStates {
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_PRESSED,
};

class Button {
public:
    Button(float positionX, float positionY, float width, float height,
           sf::Font *font, std::string text,
           sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    void render(sf::RenderTarget* target);
    void update(sf::Vector2f mousePosition);
    void updateColor();

    bool getIsPressed() const;
    bool getIsHover() const;
    bool getIsIDLE() const;
private:
    short unsigned buttonState;

    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;

    float positionX;
    float positionY;
    float width;
    float height;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
};


#endif //RPG_BUTTON_H
