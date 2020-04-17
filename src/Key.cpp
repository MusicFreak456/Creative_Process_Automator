#include"Key.hpp"

WhiteKey::WhiteKey(): height(200), width(34)
{
    this->setFillColor(sf::Color::White);
    this->setSize(sf::Vector2f(width,height));
}

BlackKey::BlackKey(): height(120), width(20)
{
    this->setFillColor(sf::Color::Black);
    this->setSize(sf::Vector2f(20,120));
}

void WhiteKey::set_note(string note)
{
    this->note = note;
}
string WhiteKey::get_note()
{
    return this->note;
}
void WhiteKey::set_value(int value)
{
    this->int_value=value;
}
int WhiteKey::get_value()
{
    return this->int_value;
}

int WhiteKey::get_height()
{
    return this->height;
}