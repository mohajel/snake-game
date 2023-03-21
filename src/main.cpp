#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include <../include/game.hpp>
#include <../include/manual.hpp>

using namespace std;

int main()
{
    SnakeGame game(MOVE_SPEED);
    game.start();
    
    return 0;
}