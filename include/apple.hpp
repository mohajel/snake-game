#if !defined(__APPLE__)
#define __APPLE__

#include <SFML/Graphics.hpp>
#include "manual.hpp"

class Apple
{

public:
    Apple(sf::Texture appleTexture, sf::RenderWindow *window);
    ~Apple();

    void printScore();
    void eatApple();
    void draw();

    Coordinate getCordinates();


private:

    Coordinate getRandomCoordinate();

    int scoreCount;
    Coordinate coordinate;
    sf::Texture appleTexture;
    sf::Sprite appleSprite;
    sf::RenderWindow *wind;
};



#endif // __APPLE__
