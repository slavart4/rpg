#ifndef RPG_ENTITY_H
#define RPG_ENTITY_H

#include "../constants.h"

class Entity
{
public:
    Entity();
    virtual ~Entity();

    virtual void move(const float& deltaTime, float dir_x, float dir_y);

    virtual void update(const float &deltaTime);
    virtual void render(sf::RenderTarget *target);
private:

protected:
    sf::RectangleShape shape;
    float movementSpeed;
};



#endif //RPG_ENTITY_H
