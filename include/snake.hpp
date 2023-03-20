#if !defined(__SNAKE__)
#define __SNAKE__

#include "manual.hpp"

class Snake
{

public:
    Snake(sf::Texture body, sf::Texture head, sf::RenderWindow *window);
    ~Snake();

    void draw();
    bool move(Direction direction);
    bool isDead();


private:
    bool dead;
    sf::Texture body;
    sf::Texture head;
    sf::RenderWindow *window;
};




#endif // __SNAKE__
