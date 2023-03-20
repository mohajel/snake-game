#if !defined(__SNAKE__)
#define __SNAKE__

#include <list>

#include "manual.hpp"
#include "apple.hpp"


class Snake
{

public:
    Snake(sf::Texture body, sf::Texture head, sf::RenderWindow *window);
    ~Snake();

    void draw();
    bool move(Direction direction, Apple *apple);
    bool isDead();

    void printDirections();


private:
    void drawBody(Coordinate *coordinate);
    void drawHead(Coordinate *coordinate);

    bool canEatApple(Coordinate appleCoordinate);
    bool isValidCoordinate(int x, int y);

    void createInitialCoordinate();

    bool dead;
    sf::Texture body;
    sf::Texture head;
    sf::RenderWindow *window;
    std::list<Coordinate> snakeCoordinate;

};




#endif // __SNAKE__
