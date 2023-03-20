#if !defined(__GAME__)
#define __GAME__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "snake.hpp"
#include "apple.hpp"

class SnakeGame
{
public:
    SnakeGame(int speed);
    ~SnakeGame();
    void start();

private:
    Direction direction;

    bool gameFinished;
    bool keyPressed;
    bool paused;
    int speed;
    void getTextures();
    void createBackgroundSprite();
    void handleEvents(sf::Event *event);
    void exitGame();

    sf::RenderWindow *window;
    sf::Texture snakeBodyTexture;
    sf::Texture backgroundTexture;
    sf::Texture snakeHeadTexture;
    sf::Texture appleTexture;

    sf::Sprite backgroundSprite;
    Snake *snake;
    Apple *apple;

};

#endif // __GAME__
