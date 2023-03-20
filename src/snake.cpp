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
    Coordinate appleCooridinate = apple->getCordinates();
    Coordinate head = this->snakeCoordinate.back();

    int x = head.x;
    int y = head.y;

    switch (direction)
    {
        case Direction::up: y --; break;
        case Direction::right: x ++; break;
        case Direction::left: x --; break;
        case Direction::down: y ++; break;
    }
    if (!isValidCoordinate(x, y))
    {
        cout << "WAY_WAY_WAY" << endl;
        this->dead = true;
    }
    this->snakeCoordinate.back().direction = direction;
    this->snakeCoordinate.push_back(Coordinate{x, y, direction});

    if (canEatApple(appleCooridinate))
        apple->eatApple();
    else
        this->snakeCoordinate.pop_front();

    return false;
}

bool Snake::isDead()
{
    return this->dead;
}

void Snake::printDirections()
{
    for (auto const& c : this->snakeCoordinate) 
        cout << c.direction << "...";
}

void Snake::drawBody(Coordinate *coordinate)
{
    sf::Sprite bodySprite;
    float x = coordinate->x;
    float y = coordinate->y;
    switch (coordinate->direction)
    {
        case Direction::right: 
            x ++; bodySprite.setRotation(90);
        break;
        case Direction::left: 
            y ++; bodySprite.setRotation(270);
        break;
        case Direction::down: 
            x ++; y ++; bodySprite.setRotation(180);
        break;
    }
    bodySprite.setTexture(this->body);
    bodySprite.setPosition(sf::Vector2f(x * Tile_SIZE, y * Tile_SIZE));
    bodySprite.setScale(sf::Vector2f(SNAKE_SIZE_SCALE, SNAKE_SIZE_SCALE));
    window->draw(bodySprite);

    switch (coordinate->direction)
    {
        case Direction::up: y -= 0.5; break;
        case Direction::right: x += 0.5; break;
        case Direction::left: x -= 0.5; break;
        case Direction::down: y += 0.5; break;
    }
    bodySprite.setPosition(sf::Vector2f(x * Tile_SIZE, y * Tile_SIZE));
    bodySprite.setColor(BODY_SECOND_COLOUR);
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
            x ++; headSprite.setRotation(90);
        break;
        case Direction::left:
            y ++; headSprite.setRotation(270);
        break;
        case Direction::down:
            x ++; y ++; headSprite.setRotation(180);
        break;
    }
    headSprite.setTexture(this->head);
    headSprite.setPosition(sf::Vector2f(x * Tile_SIZE, y * Tile_SIZE));
    headSprite.setScale(sf::Vector2f(SNAKE_SIZE_SCALE, SNAKE_SIZE_SCALE));
    window->draw(headSprite);
}

bool Snake::canEatApple(Coordinate appleCoordinate)
{
    for (auto const& c : this->snakeCoordinate) 
        if (c.x == appleCoordinate.x && c.y == appleCoordinate.y)
            return true;
    return false;
}

bool Snake::isValidCoordinate(int x, int y)
{
    if (x < 0 || y < 0 || x >= MAX_TILES_NUMBER || y >= MAX_TILES_NUMBER)
        return false;
    for (auto const& c : this->snakeCoordinate) //touching itself
        if (x == c.x && y == c.y)
            return false;
    return true;
}

void Snake::createInitialCoordinate()
{
    Coordinate c1 {4, 4, Direction::right};
    Coordinate c2 {5, 4, Direction::right};
    Coordinate c3 {6, 4, Direction::right};

    snakeCoordinate.push_back(c1);
    snakeCoordinate.push_back(c2);
    snakeCoordinate.push_back(c3);
}
