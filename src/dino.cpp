#include "dino.h"

/*
Dino class 
3 Aug , 2023
*/

Dino::Dino(sf::Vector2f pos) {

    this->isGameOver = false;
    this->jumped = false;
    this->fallSpeed = 2.f;

    this->pos = pos;

    this->texture = std::make_shared<sf::Texture>();

    if (!(this->texture->loadFromFile("/Users/ahmadodeh/Coding/Dino-Game/src/imgs/Dino_Idle.png"))) {
        exit(EXIT_FAILURE);
    }
    this->sprite.setTexture(*this->texture);
    this->sprite.setPosition(this->pos);
}

Dino::~Dino()
{}

bool Dino::isLosing() {
    return this->isGameOver;
}

void Dino::lost(Cactus& c) {

    // I fixed it (kinda)
    if ((int)c.getPos().x == 88 && (int)this->pos.y >=  350 - c.getSprite().getGlobalBounds().height) {
        this->isGameOver = true;
        
    }
}

sf::Vector2f Dino::getPos() {
    return this->pos;
}

void Dino::dinoJump() {

    bool d = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (this->pos.y < 350 && this->pos.y > 203) d = true;

    if (d && this->pos.y > 200 && !this->jumped)
        this->pos.y -= this->fallSpeed;

    if ((int)this->pos.y == (203 - this->fallSpeed) + 1) {
        this->jumped = true;
        return;
    }
}

void Dino::fall() {

    if (this->jumped && (int)this->pos.y != 350) { 
        this->pos.y += this->fallSpeed;
    }
    
    if ((int)this->pos.y == 350) this->jumped = false;
}

void Dino::collide() {
    if (this->pos.y + this->sprite.getGlobalBounds().height < 300) {
        this->pos.y = 300 - this->sprite.getGlobalBounds().height;
    }

    if (!this->pos.y)
        this->pos.y = 0;

}

void Dino::animation() {

    if (static_cast<int64_t>(5.f * this->c.getElapsedTime().asSeconds()) % 2) {
        if(!this->texture->loadFromFile("/Users/ahmadodeh/Coding/Dino-Game/src/imgs/Dino_Run01.png"))
            exit(EXIT_FAILURE);
    }

    else {
        if(!this->texture->loadFromFile("/Users/ahmadodeh/Coding/Dino-Game/src/imgs/Dino_Run02.png"))
            exit(EXIT_FAILURE);
    }

    this->sprite.setTexture(*this->texture);

}

void Dino::update() {

    this->collide();

    this->dinoJump();
    this->fall();

    this->animation();

    this->sprite.setPosition(this->pos);
}

void Dino::draw(sf::RenderWindow& window) {

    window.draw(this->sprite);
}