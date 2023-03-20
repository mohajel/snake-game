// In the Name of God

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/game.hpp"
#include "../include/manual.hpp"
#include "../include/snake.hpp"
#include "../include/apple.hpp"


using namespace std;

SnakeGame::SnakeGame(int speed = 1)
    :
    speed(speed),
    gameFinished(false),
    direction(startDirection)
{
    this->getTextures();
    this->createBackgroundSprite();
    this->window = new sf::RenderWindow(
        sf::VideoMode(WINDOWS_SIZE, WINDOWS_SIZE), GAME_HEADER_NAME);

    this->snake = new Snake(this->snakeBodyTexture, 
                            this->snakeHeadTexture, this->window);
    
    this->apple = new Apple(this->appleTexture, this->window);
}

SnakeGame::~SnakeGame()
{
    this->exitGame();
    window->close();
    delete this->window;
    delete this->snake;
    delete this->apple;
}

void SnakeGame::start()
{
    sf::Clock clock;
    while (!this->gameFinished)
    {
        sf::Time elapsedTime = clock.getElapsedTime();
        sf::Event event;
        while (window->pollEvent(event))
            this->handleEvents(& event);

        if(elapsedTime.asMilliseconds() >= MAX_MOVE_SPEED / this->speed)
        {
            elapsedTime = clock.restart();
            snake->move(this->direction, this->apple);
            if (snake->isDead())
                this->gameFinished = true;
        }

        window->clear();
        
        window->draw(backgroundSprite);
        apple->draw();
        snake->draw();

        window->display();
    }
}

void SnakeGame::getTextures()
{
    if (!this->snakeBodyTexture.loadFromFile(SNAKE_BODY))
        cerr << "CANT LOAD " << SNAKE_BODY << endl;
    if (!this->snakeHeadTexture.loadFromFile(SNAKE_HEAD))
        cerr << "CANT LOAD " << SNAKE_HEAD << endl;
    if (!this->backgroundTexture.loadFromFile(BACKGROUND_IMG))
        cerr << "CANT LOAD " << BACKGROUND_IMG << endl;

    if (!this->appleTexture.loadFromFile(APPLE_IMAGE))
    cerr << "CANT LOAD " << APPLE_IMAGE << endl;

    this->backgroundTexture.setSmooth(true);
    this->snakeHeadTexture.setSmooth(true);
    this->snakeBodyTexture.setSmooth(true);
    this->appleTexture.setSmooth(true);
    this->backgroundTexture.setRepeated(true);
}

void SnakeGame::createBackgroundSprite()
{
    this->backgroundSprite.setScale(sf::Vector2f(0.8, 0.8));
    this->backgroundSprite.setTexture(this->backgroundTexture);
    this->backgroundSprite.setTextureRect(sf::IntRect(-5, -5, 5000, 5000));
}

void SnakeGame::handleEvents(sf::Event * event)
{
    if (event->type == sf::Event::Closed)
    {
        cout << "WINDOWS_CLOSE_EVENT" << endl;
        this->gameFinished = true;
    }
    else if (event->type == sf::Event::LostFocus)
    {
        cout << "WINDOWS_LOST_FOCUS" << endl;
    }
    else if (event->type == sf::Event::GainedFocus)
    {
        cout << "WINDOWS_GAINED_FOCUS" << endl;
    }
    else if (event->type == sf::Event::TextEntered)
    {
        cout << "TEXT_ENTERED::" << static_cast<char>(event->text.unicode) << endl;
    }
    else if (event->type == sf::Event::KeyPressed)
    {
        if (event->key.code == sf::Keyboard::Right)
        {
            cout << "RIGHT_KEY_PRESSED" << endl;
            this->direction = Direction::right;
        }
        else if (event->key.code == sf::Keyboard::Left)
        {
            cout << "LEFT_KEY_PRESSED" << endl;
            this->direction = Direction::left;
        }
        else if (event->key.code == sf::Keyboard::Up)
        {
            cout << "UP_KEY_PRESSED" << endl;
            this->direction = Direction::up;
        }
        else if (event->key.code == sf::Keyboard::Down)
        {
            cout << "DOWN_KEY_PRESSED" << endl;
            this->direction = Direction::down;
        }
    }
    else if (event->type == sf::Event::MouseButtonPressed)
    {
        if (event->mouseButton.button == sf::Mouse::Right)
        {
            cout << "right click" << endl;
        }  
        else if (event->mouseButton.button == sf::Mouse::Left)
        {
            cout << "left click" << endl;
        }  
    }
}

void SnakeGame::exitGame()
{
    cout << "***\tGAME FINISHED\t***" << endl;
    cout << "*******************************************" << endl;
    apple->printScore();
}