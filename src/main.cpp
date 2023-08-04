

/*


@author : Ahmad Odeh aka Undeined010
@about  : a dino chrome clone game with a twist 
@Date   : Tuesday , 1st Aug 2023


*/


#include "dino.h"
#include "cactus.h"

// test function remove it later

void logPos(const char* name,const sf::Vector2f& p) {
    if (name == nullptr) return;
    printf("%s -> {x : %0.3f , y : %0.3f}\n",name,p.x , p.y);
}

int main() {

    
    sf::RenderWindow window(sf::VideoMode(600,450),"Dino Game");
    sf::Event e;

    std::shared_ptr<sf::Texture> ground_texture = std::make_shared<sf::Texture>();
    if (!ground_texture->loadFromFile("/Users/ahmadodeh/Coding/Dino-Game/src/imgs/Ground.png"))
        exit(EXIT_FAILURE);

    sf::Sprite sprite;
    sprite.setTexture(*ground_texture);
    sprite.setPosition(0,350);

    Dino d(sf::Vector2f(0,350));

    Cactus c(sf::Vector2f(400,350));

    window.setFramerateLimit(120);
    while (window.isOpen()) {

        while (window.pollEvent(e)) {
            
            if (e.type == sf::Event::Closed)
                window.close();
            // remove it l8r
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) )
                window.close();
        }        

        window.clear(sf::Color::Black);
        window.draw(sprite);

        d.lost(c);

        c.update();
        c.draw(window);

        d.update();
        d.draw(window);



        if (d.isLosing()) {
            fprintf(stdout,"GAME OVER \n");
            
            window.close();
        }

        window.display();


    }

    return 0;
}