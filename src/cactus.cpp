#include "cactus.h"

#include <random>
#include <ctime>

Cactus::Cactus(sf::Vector2f pos) {
    this->pos = pos;
    this->texture = std::make_shared<sf::Texture>();

    this->speed = 2.0f;

    if (!this->texture->loadFromFile("src/imgs/Cactus_Small_Triple.png"))
        exit(EXIT_FAILURE);
    
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->pos);
}

Cactus::~Cactus()
{}

sf::Sprite Cactus::getSprite() {
    return this->sprite;
}

sf::Vector2f Cactus::getPos() {
    return this->pos;
}

void Cactus::randomTexture() {

    srand(time(0));

    int temp = (int) rand() % 100;

    if (temp % 2) {
        if(!this->texture->loadFromFile("/Users/ahmadodeh/Coding/Dino-Game/src/imgs/Cactus_Small_Single.png"))
            exit(EXIT_FAILURE);
    }

    else {
        if(!this->texture->loadFromFile("/Users/ahmadodeh/Coding/Dino-Game/src/imgs/Cactus_Small_Triple.png"))
            exit(EXIT_FAILURE);
    }
    
    this->sprite.setTexture(*this->texture);

}

void Cactus::spawn() {
    if (this->pos.x <= 0.f - this->sprite.getGlobalBounds().width) {
        this->pos.x = 700 - this->sprite.getGlobalBounds().width;
        this->randomTexture();

    }
}

void Cactus::update()
{
    // todo: need to add a start function later

    this->spawn();

    this->pos.x -= this->speed;


    this->sprite.setPosition(this->pos);
}

void Cactus::draw(sf::RenderWindow& wind) {
    wind.draw(this->sprite);
}