#include"Key.hpp"

WhiteKey::WhiteKey()
{
    this->active = false;
    this->setFillColor(sf::Color::White);
    this->setSize(sf::Vector2f(Width,Height));
}

BlackKey::BlackKey()
{
    this->active = false;
    this->setFillColor(sf::Color::Black);
    this->setSize(sf::Vector2f(Width,Height));
}

void WhiteKey::set_note(string note)
{
    this->note = note;
}
string WhiteKey::get_note()
{
    return this->note;
}
void WhiteKey::set_value(float value)
{
    this->value=value;
}
float WhiteKey::get_value()
{
    return this->value;
}

void WhiteKey::reset_color()
{
    this->setFillColor(sf::Color::White);
}
void BlackKey::reset_color()
{
    this->setFillColor(sf::Color::Black);
}

void WhiteKey::highlight()
{
    this->setFillColor(sf::Color(255,219,77));
}
void BlackKey::highlight()
{
    this->setFillColor(sf::Color(230,184,0));
}