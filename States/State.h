#ifndef RPG_STATE_H
#define RPG_STATE_H

#include "../Entities/Entity.h"
#include "../Controls/Mouse.h"

class StateContext;
class State;

class State
{
protected:
    StateContext *context_;
    sf::RenderWindow* window;
    Mouse *mouse;

    std::map <std::string, int> *supportedKeys;
    std::map <std::string, int> keyBinds;
    bool quit;

    std::vector<sf::Texture> textures;

    virtual void initKeyBinds() = 0;
public:
    State(sf::RenderWindow* window, Mouse *mouse, std::map <std::string, int> *supportedKeys);
    virtual ~State();

    void set_context(StateContext *context) {
        this->context_ = context;
    }

    const bool& getQuit() const;

    virtual void checkForQuit();
    virtual void endState() = 0;

    virtual void updateMousePositions();
    virtual void updateInput(const float& deltaTime) = 0;
    virtual void update(const float& deltaTime) = 0;
    virtual void render(sf::RenderTarget* target) = 0;
};


// State machine stuff
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
