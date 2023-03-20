// In the Name of God

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/snake.hpp"
#include "../include/manual.hpp"

using namespace std;

Snake::Snake(sf::Texture body, sf::Texture head, sf::RenderWindow *window)
    :
    body(body),
    head(head),
    window(window),
    dead(false)
{
}

Snake::~Snake()
{

}

void Snake::draw()
{
}

bool Snake::move(Direction direction)
{


    return false;
}

bool Snake::isDead()
{
    return this->dead;
}
