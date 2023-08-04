#ifndef DINO_H_
#define DINO_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include <string>

#include "cactus.h"

class Dino {
    sf::Vector2f pos;
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    sf::Clock c;
    bool jumped;

    float fallSpeed;
    bool isGameOver;

    public:
        Dino(sf::Vector2f pos);
        ~Dino();

    public:
        sf::Vector2f getPos();
        bool isLosing();
        void lost(Cactus& c);

    private:
        void animation();
        void collide();
        void dinoJump();
        void fall();

    public:
        void update();
        void draw(sf::RenderWindow& window);
    
};

#endif