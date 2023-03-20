#if !defined(__GAME__)
#define __GAME__

#include <SFML/Graphics.hpp>
#include <iostream>

class SnakeGame
{

public:
    SnakeGame(int x);
    void start();

private:
    void getTextures();
    void createBackgroundSprite();
    void handleEvents(sf::Event *event);

    sf::Texture snakeBodyTexture;
    sf::Texture backgroundTexture;
    sf::Texture snakeHeadTexture;

    sf::Sprite backgroundSprite;
};



#endif // __GAME__
