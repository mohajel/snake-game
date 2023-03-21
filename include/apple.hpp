#if !defined(__APPLE__)
#define __APPLE__

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
    void playEatAppleSound();

    int scoreCount;
    Coordinate coordinate;
    sf::Texture appleTexture;
    sf::Sprite appleSprite;
    sf::RenderWindow *wind;
    sf::SoundBuffer appleSoundBuffer;
    sf::Sound appleSound;
};



#endif // __APPLE__
