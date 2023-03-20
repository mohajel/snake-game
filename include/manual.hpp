#if !defined(__MANUAL__)
#define __MANUAL__

#include <string>

enum Direction{right, left, up, down};
const Direction startDirection = Direction::right;


const int WINDOWS_SIZE = 540;
const int MAX_MOVE_SPEED = 1000;
const int MOVE_SPEED = 1; // 1 for slowest, 4 for fastest

const std::string GAME_HEADER_NAME = "__SNAKE__GAME__";
const std::string BACKGROUND_IMG = "./pictures/Background1.jpg";
const std::string SNAKE_BODY = "./pictures/SnakeBody.png";
const std::string SNAKE_HEAD = "./pictures/SnakeHead.png";



#endif // __MANUAL__
