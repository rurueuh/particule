/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** MouvementCompenant
*/

#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>


class MouvementCompenant {
    public:
        MouvementCompenant(sf::Vector2f);
        ~MouvementCompenant();

        void update(sf::Vertex &);
        void move(sf::Vertex &);

        void setSpeed(sf::Vector2f speed) {_speed = speed;};
        sf::Vector2f getSpeed() {return _speed;};

    protected:
    private:
        sf::Vector2f _speed;
        float _decrease = 0.01;
};
