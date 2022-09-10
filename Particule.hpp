/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** Particule
*/

#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include "MouvementCompenant.hpp"

class Particule {
    public:
        Particule(sf::Vector2f pos, sf::Vector2f speed, sf::Color color);
        ~Particule();

        MouvementCompenant *_mouvementCompenant;

        void update();
        void draw(sf::RenderWindow &window);
        void randomSpeed() {_mouvementCompenant->setSpeed(sf::Vector2f(static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 10) * (rand() % 2 == 0 ? 1 : -1), static_cast <float> (rand()) / static_cast <float> (RAND_MAX / 10) * (rand() % 2 == 0 ? 1 : -1)));};
        void setPosition(sf::Vector2f pos) { _vertex.position = pos; };

        sf::Vertex &getVertex() { return _vertex; };

        void Aspiration(sf::Vector2f pos);

        bool _isAspiration = false;
    protected:
    private:
        sf::Vertex _vertex;
};
