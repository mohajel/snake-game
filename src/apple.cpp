// In the Name of God

#include <iostream>
#include <SFML/Graphics.hpp>

#include "../include/apple.hpp"

using namespace std;

Apple::Apple(sf::Texture appleTexture, sf::RenderWindow *window)
    :
    scoreCount(0),
    appleTexture(appleTexture),
    wind(window)
{
    appleSprite.setTexture(this->appleTexture);
    appleSprite.setScale(sf::Vector2f(0.4, 0.4));
    this->coordinate = this->getRandomCoordinate();
}

Apple::~Apple()
{

}

void Apple::eatApple()
{
    cout << "GOOD_JOB - SCORE:" << this->scoreCount << endl;
    this->scoreCount ++;
    this->coordinate = this->getRandomCoordinate();
}

void Apple::draw()
{
    appleSprite.setPosition(sf::Vector2f
        (coordinate.x * Tile_SIZE, 
        coordinate.y * Tile_SIZE));

    this->wind->draw(this->appleSprite);
}

Coordinate Apple::getCordinates()
{
    return this->coordinate;
}

Coordinate Apple::getRandomCoordinate()
{
    int randomX = rand() % MAX_TILES_NUMBER;
    int randomY = rand() % MAX_TILES_NUMBER;
    cout << "x = " << randomX << " y = " << randomY << endl;
    return Coordinate{randomX, randomY, Direction::right};
}

void Apple::printScore()
{
    cout << "YOUR_FINAL_SCORE::" << this->scoreCount << endl;
}
