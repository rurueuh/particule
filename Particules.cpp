/*
** EPITECH PROJECT, 2022
** particule sfml
** File description:
** Particules
*/

#include "Particules.hpp"

static int getParticulesNumber() {
    std::ifstream file("config.ruru");
    std::string line;
    int nb = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("nb_particules") != std::string::npos) {
                nb = std::stoi(line.substr(line.find("=") + 1));
                break;
            }
        }
        file.close();
    }
    if (nb == 0)
        nb = NB_PARTICULES;
    return nb;
}

Particules::Particules()
{
    const int nbParticules = getParticulesNumber();
    sf::Vector2f pos_diff = sf::Vector2f();
    std::uniform_int_distribution<int> distributionx(0, 960);
    std::uniform_int_distribution<int> distributiony(0, 540);
    std::random_device rd;
    std::mt19937 engine(rd());

    for (int i = 0; i < nbParticules; i++) {
        pos_diff.x = distributionx(engine);
        pos_diff.y = distributiony(engine);
        sf::Uint8 orange = pos_diff.x / 960 * 255;
        sf::Color color = sf::Color(255, orange, 0, 255);
        _particules.push_back(new Particule(pos_diff + (sf::Vector2f) {1920 / 2, 1080 / 2}, sf::Vector2f(0, 0), color));
    }
}

Particules::~Particules()
{
}

void Particules::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        for (auto &particule : _particules) {
            particule->randomSpeed();
        }
    }

    for (auto &particule : _particules) {
        particule->update();

    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->_isAspiration = true;
        sf::Vector2i mousePos = sf::Mouse::getPosition();
        for (auto &particule : _particules) {
            particule->Aspiration(sf::Vector2f(mousePos.x, mousePos.y));
        }
    }

    if (this->_isAspiration == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) == false && sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        this->_isAspiration = false;
        for (auto &particule : _particules) {
            if (particule->_isAspiration == true) {
                particule->_isAspiration = false;
                // particule->randomSpeed();
            }
        }
    }
}

void Particules::draw(sf::RenderWindow &window)
{
    auto particules = this->getParticules();
    _vertexArray.clear();
    for (auto &particule : particules) {
        _vertexArray.append(particule->getVertex());
    }
    window.draw(_vertexArray, sf::BlendAdd);
}

std::vector<Particule *> Particules::getParticules() const
{
    return _particules;
}

void Particules::addParticule(sf::Vector2f pos, sf::Vector2f speed, sf::Color color)
{
    Particule *particule = new Particule(pos, speed, color);
    _particules.push_back(particule);
}
