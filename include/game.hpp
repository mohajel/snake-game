#if !defined(__GAME__)
#define __GAME__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "snake.hpp"

class SnakeGame
{

public:
    SnakeGame(int speed);
    ~SnakeGame();

    void start();

private:

    Direction direction;

    bool gameFinished;
    int speed;
    void getTextures();
    void createBackgroundSprite();
    void handleEvents(sf::Event *event);
    void exitGame();

    sf::RenderWindow *window;
    sf::Texture snakeBodyTexture;
    sf::Texture backgroundTexture;
    sf::Texture snakeHeadTexture;

    sf::Sprite backgroundSprite;
    Snake *snake;

};



#endif // __GAME__
