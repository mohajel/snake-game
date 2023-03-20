// In the Name of God

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/game.hpp"
#include "../include/manual.hpp"

using namespace std;

SnakeGame::SnakeGame(int x)
{
    this->getTextures();
    this->createBackgroundSprite();
}

void SnakeGame::start()
{
    sf::RenderWindow window(sf::VideoMode(WINDOWS_SIZE, WINDOWS_SIZE), GAME_HEADER_NAME);
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        cout << elapsed.asMilliseconds() << endl;

        sf::Event event;
        while (window.pollEvent(event))
            this->handleEvents(& event);

        window.clear();

        window.draw(backgroundSprite);
        // window.draw(shape);
        // window.draw(sprite);
        // window.draw(sp1);
        // window.draw(sp2);
        // window.draw(sp3);
        window.display();
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

    this->backgroundTexture.setSmooth(true);
    this->snakeHeadTexture.setSmooth(true);
    this->snakeBodyTexture.setSmooth(true);

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
                cout << "close windows ..." << endl;
                // window.close();

            else if (event->type == sf::Event::LostFocus)
            {
                cout << "lost focous..." << endl;
            }
            else if (event->type == sf::Event::GainedFocus)
            {
                cout << "gained focous..." << endl;
            }
            else if (event->type == sf::Event::TextEntered)
            {
                cout << "char::" << static_cast<char>(event->text.unicode) << endl;
            }
            else if (event->type == sf::Event::KeyPressed)
            {
                if (event->key.code == sf::Keyboard::Right)
                {
                    cout << "go right.." << endl;
                }
                else if (event->key.code == sf::Keyboard::Left)
                {
                    cout << "go left.." << endl;
                }
                else if (event->key.code == sf::Keyboard::Up)
                {
                    cout << "go up.." << endl;
                }
                else if (event->key.code == sf::Keyboard::Down)
                {
                    cout << "go down.." << endl;
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