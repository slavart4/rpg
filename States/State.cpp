#include "State.h"

State::State(sf::RenderWindow* window, Mouse *mouse, std::map <std::string, int> *supportedKeys):
window(window), mouse(mouse), supportedKeys(supportedKeys) {
    this->window = window;
    this->quit = false;
}

State::~State() {

}

const bool& State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keyBinds["CLOSE"])))
    {
        this->quit = true;
    }
}

void State::updateMousePositions() {
    this->mouse->updateMousePosition();
}


StateContext::StateContext(State *state) {
this->state_ = state;
this->state_->set_context(this);
}

StateContext::~StateContext() {
    delete this->state_;
}

void StateContext::TransitionTo(State *state) {
    delete this->state_;
    this->state_ = state;
    this->state_->set_context(this);
}

void StateContext::update(const float &deltaTime) {
    this->state_->update(deltaTime);
}

void StateContext::render(sf::RenderTarget *target) {
    this->state_->render(target);
}

void StateContext::endState() {
    this->state_->endState();
}

const bool &StateContext::getQuit() const {
    return this->state_->getQuit();
}
