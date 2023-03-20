#if !defined(__MANUAL__)
#define __MANUAL__

#include <string>

#define SNAKE_SIZE_SCALE 0.2

enum Direction{right, left, up, down};

struct Coordinate
{
    int x;
    int y;
    Direction direction;
};


const Direction startDirection = Direction::right;

const int MAX_TILES_NUMBER = 12;
const int WINDOWS_SIZE = 540;
const int Tile_SIZE = WINDOWS_SIZE / MAX_TILES_NUMBER;
const int MAX_MOVE_SPEED = 1000;
const int MOVE_SPEED = 5; // 1 for slowest, 4 for fastest

const std::string GAME_HEADER_NAME = "__SNAKE__GAME__";
const std::string BACKGROUND_IMG = "./pictures/Background1.jpg";
const std::string SNAKE_BODY = "./pictures/SnakeBody.png";
const std::string SNAKE_HEAD = "./pictures/SnakeHead.png";
const std::string APPLE_IMAGE = "./pictures/AppleImage.png";



#endif // __MANUAL__
