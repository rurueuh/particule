/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** Particule
*/

#include "Particule.hpp"

Particule::Particule(sf::Vector2f pos, sf::Vector2f speed, sf::Color color)
{
    _vertex.position = pos;
    _vertex.color = color;

    _mouvementCompenant = new MouvementCompenant(speed);
}

Particule::~Particule()
{
    if (_mouvementCompenant)
        delete _mouvementCompenant;
}

void Particule::Aspiration(sf::Vector2f pos)
{
    const int range = 1920; // range of attraction
    const float speed = 0.02; // speed of attraction
    sf::Vector2f direction = pos - _vertex.position;
    float distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    float ratio = 1 - (distance / range);
    this->_isAspiration = true;
    _mouvementCompenant->setSpeed(direction * speed * ratio);
}

void Particule::update()
{
    if (_mouvementCompenant == nullptr){
        std::cout << "null" << std::endl;
        return;
    }
    _mouvementCompenant->update(_vertex);
}
