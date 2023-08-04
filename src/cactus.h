#ifndef CACTUS_H_
#define CACTUS_H_

#include <memory>
#include <SFML/Graphics.hpp>

class Cactus {
    sf::Vector2f pos;
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;


    float speed;

    public:
        Cactus(sf::Vector2f p);
        ~Cactus();

    public:
        sf::Vector2f getPos();
        sf::Sprite getSprite();

    private:
        void spawn();
        void randomTexture();

    public:
        void update();
        void draw(sf::RenderWindow& wind);
};

#endif