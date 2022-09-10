/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** Particules
*/

#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include <winuser.h>
#include "Particule.hpp"

typedef struct {
    sf::RenderTexture *texture;
    std::vector<Particule *> particules;
    int i;
    int j;
} draw_particule_t;

#define NB_PARTICULES 200000

class Particules {
    public:
        Particules();
        ~Particules();

        void update();
        void draw(sf::RenderWindow &window);

        std::vector<Particule *> getParticules() const;
        void addParticule(sf::Vector2f pos, sf::Vector2f speed, sf::Color color);

        bool isAspiration() const { return _isAspiration; };

    protected:
    private:
        bool _isAspiration = false;
        std::vector<Particule *> _particules;
        sf::VertexArray _vertexArray;
};
