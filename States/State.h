#ifndef RPG_STATE_H
#define RPG_STATE_H

#include "../Entities/Entity.h"

class StateContext;
class State;

class State
{
protected:
    StateContext *context_;

    sf::RenderWindow* window;
    std::map <std::string, int> *supportedKeys;
    std::map <std::string, int> keyBinds;
    bool quit;

    //TODO: replace to a separate class
    sf::Vector2i mousePositionScreen;
    sf::Vector2i mousePositionWindow;
    sf::Vector2f mousePositionView;

    std::vector<sf::Texture> textures;

    virtual void initKeyBinds() = 0;
public:
    State(sf::RenderWindow* window, std::map <std::string, int> *supportedKeys);
    virtual ~State();

    void set_context(StateContext *context) {
        this->context_ = context;
    }

    const bool& getQuit() const;

    virtual void checkForQuit();
    virtual void endState() = 0;

    virtual void updateMosePositions();
    virtual void updateInput(const float& deltaTime) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(sf::RenderTarget* target) = 0;
};

class StateContext {
private:
    State *state_;

public:
    explicit StateContext(State *state);
    ~StateContext();

    void TransitionTo(State *state);

    void update(const float& deltaTime);
    void render(sf::RenderTarget* target);

    void endState();
    const bool& getQuit() const;
};

#endif //RPG_STATE_H
