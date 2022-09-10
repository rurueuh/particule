/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** MouvementCompenant
*/

#include "MouvementCompenant.hpp"

MouvementCompenant::MouvementCompenant(sf::Vector2f speed)
{
    _speed = speed;
}

MouvementCompenant::~MouvementCompenant()
{
}

void MouvementCompenant::update(sf::Vertex &vertex)
{
    if (abs(_speed.x) < _decrease) {
        _speed.x = 0;
    } else {
        if (_speed.x > 0) {
            _speed.x -= _decrease;
        } else {
            _speed.x += _decrease;
        }
    }
    if (abs(_speed.y) < _decrease) {
        _speed.y = 0;
    } else {
        if (_speed.y > 0) {
            _speed.y -= _decrease;
        } else {
            _speed.y += _decrease;
        }
    }
    this->move(vertex);
}

void MouvementCompenant::move(sf::Vertex &vertex)
{
    sf::Vertex *v = &vertex;
    vertex.position += _speed;
    if (vertex.position.x > 1920 || vertex.position.x < 0){
        if (vertex.position.x > 1920)
            vertex.position.x = 1920;
        else
            vertex.position.x = 0;
        _speed.x *= -1;
    }
    if (vertex.position.y > 1080 || vertex.position.y < 0){
        if (vertex.position.y > 1080)
            vertex.position.y = 1080;
        else
            vertex.position.y = 0;
        _speed.y *= -1;
    }
}
