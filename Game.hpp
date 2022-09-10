/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** Game
*/

#pragma once

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <Windows.h>
#include "Particules.hpp"

class Game {
    public:
        Game();
        virtual ~Game();

        void run();

        void update();
        void render();
        void events();

        Particules *_particules;

    protected:
    private:
        sf::RenderWindow _window;
        sf::Event _event;

        sf::Clock _clock_fps;
        sf::Text _text_fps;
        sf::Font _font;
};
