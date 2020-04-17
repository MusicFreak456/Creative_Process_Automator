#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include"Key.hpp"
#include<vector>

using namespace std;

class Keyboard :public sf::Drawable
{
private:
    vector<WhiteKey> white_keys;
    vector<BlackKey> black_keys;
    const int number_of_white_keys;
    const int number_of_black_keys;
public:
    Keyboard();
    void movePosition(float,float);
    Key* mouse_over(sf::Vector2f);

private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif