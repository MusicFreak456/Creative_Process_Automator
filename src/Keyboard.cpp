#include"Keyboard.hpp"

Keyboard::Keyboard(): number_of_white_keys(52), number_of_black_keys(1)
{
    int spacing = 2;
    for(int i=1;i<=number_of_white_keys;i++)
    {
        WhiteKey new_key;
        new_key.set_value(i);
        new_key.setPosition(sf::Vector2f((i-1)*new_key.getSize().x + (i-1)* spacing,0));
        white_keys.push_back(new_key);
    }
}

void Keyboard::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    for(const WhiteKey & k : white_keys)
    {
        target.draw(k);
    }
}

void Keyboard::movePosition(float x, float y)
{
    for(WhiteKey & k : white_keys)
    {
        float xcoord = k.getPosition().x;
        float ycoord = k.getPosition().y;
        k.setPosition(sf::Vector2f(xcoord+x,ycoord+y));
    }
}

int Keyboard::get_keys_height()
{
    return white_keys[0].get_height();
}