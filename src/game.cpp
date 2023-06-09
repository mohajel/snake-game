// In the Name of God

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> 
#include <iostream>
#include <unistd.h>  

#include "../include/game.hpp"
#include "../include/manual.hpp"
#include "../include/snake.hpp"
#include "../include/apple.hpp"

using namespace std;

SnakeGame::SnakeGame(int speed = 1)
    :
    speed(speed),
    gameFinished(false),
    direction(startDirection),
    keyPressed(false),
    paused(false)
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

        if(elapsedTime.asMilliseconds() >= MAX_MOVE_SPEED / this->speed && !this->paused)
        {
            elapsedTime = clock.restart();
            snake->move(this->direction, this->apple);
            keyPressed = false;
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
        this->paused = true;
    }
    else if (event->type == sf::Event::GainedFocus)
    {
        cout << "WINDOWS_GAINED_FOCUS" << endl;
        this->paused = false;
    }
    else if (event->type == sf::Event::TextEntered)
    {
        cout << "TEXT_ENTERED::" << static_cast<char>(event->text.unicode) << endl;
    }
    else if (event->type == sf::Event::KeyPressed && keyPressed == false)
    {
        if (event->key.code == sf::Keyboard::Right && this->direction != Direction::left)
        {
            cout << "RIGHT_KEY_PRESSED" << endl;
            keyPressed = true;
            this->direction = Direction::right;
        }
        else if (event->key.code == sf::Keyboard::Left && this->direction != Direction::right)
        {
            cout << "LEFT_KEY_PRESSED" << endl;
            keyPressed = true;
            this->direction = Direction::left;
        }
        else if (event->key.code == sf::Keyboard::Up && this->direction != Direction::down)
        {
            cout << "UP_KEY_PRESSED" << endl;
            keyPressed = true;
            this->direction = Direction::up;
        }
        else if (event->key.code == sf::Keyboard::Down && this->direction != Direction::up)
        {
            cout << "DOWN_KEY_PRESSED" << endl;
            keyPressed = true;
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
    sf::SoundBuffer gameFinishBuffer;
    gameFinishBuffer.loadFromFile(GAME_FINISH_SOUND);
    sf::Sound gameFinishSound;
    gameFinishSound.setBuffer(gameFinishBuffer);
    gameFinishSound.play();
    cout << "***\tGAME FINISHED\t***" << endl;
    cout << "*******************************************" << endl;
    apple->printScore();
    sleep(TIME_TO_WAIT_AFTER_GAME_FINISHED);
}