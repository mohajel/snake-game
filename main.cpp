#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(540, 540), "SNAKE__GAME");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    sf::Texture backgroundTexture;

    backgroundTexture.setRepeated(true);

    

    if (!texture.loadFromFile("./pictures/SnakeHead.png"))
    {
        cerr << "cant load" << endl;
        exit(EXIT_FAILURE);
    }    backgroundTexture.setSmooth(true);
    if (!backgroundTexture.loadFromFile("./pictures/Background1.jpg"))
    {
        cerr << "cant load" << endl;
        exit(EXIT_FAILURE);
    }
    texture.setSmooth(true);
    sf::Sprite sprite;
    sf::Sprite backgroundSprite;

    sprite.setTexture(texture);
    // sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent
    sprite.setScale(sf::Vector2f(0.2, 0.2));
    backgroundSprite.setScale(sf::Vector2f(0.8, 0.8));

    backgroundSprite.setTexture(backgroundTexture);

    backgroundSprite.setTextureRect(sf::IntRect(0 ,0 , 5000, 5000));
    // can use thesee::
    // sprite.setPosition(sf::Vector2f(10.f, 50.f)); // absolute position
    // sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position
    // sprite.setRotation(90.f); // absolute angle

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if (event.type == sf::Event::LostFocus)
            {
                cout << "lost focous..." << endl;
            }
            else if (event.type == sf::Event::GainedFocus)
            {
                cout << "gained focous..." << endl;
            }
            else if (event.type == sf::Event::TextEntered)
            {
                cout << "char::" << static_cast<char>(event.text.unicode) << endl;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    cout << "go right.." << endl;
                }
                else if (event.key.code == sf::Keyboard::Left)
                {
                    cout << "go left.." << endl;
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    cout << "go up.." << endl;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    cout << "go down.." << endl;
                }
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    cout << "right click" << endl;
                }  
                else if (event.mouseButton.button == sf::Mouse::Left)
                {
                    cout << "left click" << endl;
                }  
            }

        }

        window.clear();

        window.draw(backgroundSprite);
        // window.draw(shape);
        window.draw(sprite);
        window.display();
    }

    return 0;
}