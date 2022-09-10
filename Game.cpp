/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    _window.create(sf::VideoMode(1920, 1080), "uwu ruru", sf::Style::Fullscreen);
    _window.setFramerateLimit(144);

    _particules = new Particules();

    _font.loadFromFile("font.ttf");
    _text_fps.setFont(_font);
    _text_fps.setCharacterSize(24);
    _text_fps.setFillColor(sf::Color::White);
}

Game::~Game()
{
    delete _particules;
}

void Game::run()
{
    while (_window.isOpen()) {
        events();
        update();
        render();
    }
}

static void update_fps(sf::Text &text, sf::Clock &clock)
{
    static int frame = 0;
    static float time = 0;

    frame++;
    time += clock.restart().asSeconds();
    if (time >= 1) {
        text.setString(std::to_string(frame));
        frame = 0;
        time = 0;
    }
}

void Game::update()
{
    _particules->update();  
    update_fps(_text_fps, _clock_fps);
}

void Game::render()
{
    _window.clear();
    _particules->draw(_window);
    _window.draw(_text_fps);
    _window.display();
}

void Game::events()
{
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed && _event.key.code == sf::Keyboard::Escape)
            _window.close();
    }
}