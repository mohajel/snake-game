// In the Name of God

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "../include/snake.hpp"
#include "../include/manual.hpp"
#include "../include/apple.hpp"

using namespace std;

Snake::Snake(sf::Texture body, sf::Texture head, sf::RenderWindow *window)
    :
    body(body),
    head(head),
    window(window),
    dead(false)
{
    this->createInitialCoordinate();

}

Snake::~Snake()
{

}

void Snake::draw()
{
    list<Coordinate>::iterator it;
    for (it = snakeCoordinate.begin(); it != prev(snakeCoordinate.end()); it++) 
        drawBody(&(*it));
    drawHead(&(*(it ++)));

}

bool Snake::move(Direction direction, Apple *apple)
{


    return false;
}

bool Snake::isDead()
{


    return this->dead;
}

void Snake::drawBody(Coordinate *coordinate)
{
    sf::Sprite bodySprite;
    float x = coordinate->x;
    float y = coordinate->y;
    switch (coordinate->direction)
    {
        case Direction::right:
            x ++;
            bodySprite.setRotation(90);
            break;
        case Direction::left:
            y ++;
            bodySprite.setRotation(270);
            break;
        case Direction::down:
            x ++;
            y ++;
            bodySprite.setRotation(180);
            break;
    }
    bodySprite.setTexture(this->body);
    bodySprite.setPosition(sf::Vector2f(x * Tile_SIZE, y * Tile_SIZE));
    bodySprite.setScale(sf::Vector2f(0.2, 0.2));
    window->draw(bodySprite);

    switch (coordinate->direction)
    {
        case Direction::up: y -= 0.5; break;
        case Direction::right: x += 0.5; break;
        case Direction::left: x -= 0,5; break;
        case Direction::down: y += 0.5; break;
    }
    bodySprite.setPosition(sf::Vector2f(x * Tile_SIZE, y * Tile_SIZE));
    window->draw(bodySprite);
}

void Snake::drawHead(Coordinate *coordinate)
{
    sf::Sprite headSprite;
    int x = coordinate->x;
    int y = coordinate->y;
    switch (coordinate->direction)
    {
        case Direction::right:
            x ++;
            headSprite.setRotation(90);
            break;
        case Direction::left:
            y ++;
            headSprite.setRotation(270);
            break;
        case Direction::down:
            x ++;
            y ++;
            headSprite.setRotation(180);
            break;
    }

    headSprite.setTexture(this->head);
    headSprite.setPosition(sf::Vector2f(x * Tile_SIZE, y * Tile_SIZE));
    headSprite.setScale(sf::Vector2f(0.2, 0.2));
    window->draw(headSprite);
}

void Snake::createInitialCoordinate()
{
    // Coordinate c1 {4, 4, Direction::down};
    // Coordinate c2 {4, 5, Direction::down};
    // Coordinate c3 {4, 6, Direction::down};

    Coordinate c1 {4, 4, Direction::down};
    Coordinate c2 {4, 5, Direction::right};
    Coordinate c3 {5, 5, Direction::up};
    Coordinate c4 {5, 4, Direction::up};
    snakeCoordinate.push_back(c1);
    snakeCoordinate.push_back(c2);
    snakeCoordinate.push_back(c3);
    snakeCoordinate.push_back(c4);
}
