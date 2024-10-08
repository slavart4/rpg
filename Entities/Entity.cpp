#include "Entity.h"

Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.f;
}

Entity::~Entity()
{

}

void Entity::move(const float& deltaTime, const float dir_x, const float dir_y)
{
    this->shape.move(dir_x * this->movementSpeed * deltaTime, dir_y * this->movementSpeed * deltaTime);
}

void Entity::update(const float &deltaTime) {

}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}
