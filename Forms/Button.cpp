#include "Button.h"

Button::Button(float positionX, float positionY, float width, float height,
               sf::Font *font, std::string text,
               sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
    this->buttonState = BTN_IDLE;

    this->font = font;
    this->idleColor = idleColor;
    this->hoverColor = hoverColor;
    this->activeColor = activeColor;

    this->shape.setPosition(sf::Vector2f(positionX, positionY));
    this->shape.setSize(sf::Vector2f (width, height));

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(18);
    this->text.setPosition(
            this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
            this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f
            );

    this->shape.setFillColor(this->idleColor);
}

Button::~Button() {

}

void Button::render(sf::RenderTarget *target) {
    target->draw(this->shape);
    target->draw(this->text);
}

void Button::update(const sf::Vector2f mousePosition) {
    //idle
    this->buttonState = BTN_IDLE;

    // hover
    if (this->shape.getGlobalBounds().contains(mousePosition)) {
        this->buttonState = BTN_HOVER;

        // pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = BTN_PRESSED;
        }
    }

    this->updateColor();
}

void Button::updateColor() {
    switch (this->buttonState) {
        case BTN_IDLE:
            this->shape.setFillColor(this->idleColor);
            break;
        case BTN_HOVER:
            this->shape.setFillColor(this->hoverColor);
            break;
        case BTN_PRESSED:
            this->shape.setFillColor(this->activeColor);
            break;
        default:
            this->shape.setFillColor(sf::Color::Red);
            break;
    }
}

bool Button::getIsPressed() const {
    if(this->buttonState == BTN_PRESSED)
        return true;
    return false;
}

bool Button::getIsHover() const {
    if(this->buttonState == BTN_HOVER)
        return true;
    return false;
}

bool Button::getIsIDLE() const {
    if(this->buttonState == BTN_IDLE)
        return true;
    return false;
}
