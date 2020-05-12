#include"Progression.hpp"

ProgressionWindow::ProgressionWindow(sf::Font& font)
{
    this->border.setPosition(304,150);
    this->border.setSize(sf::Vector2f(796,150));
    this->border.setFillColor(sf::Color(255,255,255,5));

    this->title.setFont(font);
    this->title.setString("Progression");
    this->title.setPosition(304,150);
    this->title.setCharacterSize(20);

    this->temp.setFont(font);
    this->temp.setString("Coming soon...");
    this->temp.setPosition(600,200);
    this->temp.setCharacterSize(20);
}

void ProgressionWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title, states);
    target.draw(this->temp,states);
}