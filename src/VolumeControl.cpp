#include"VolumeControl.hpp"

VolumeWindow::VolumeWindow(sf::Font& font)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1660,0);
    this->title.setString("volume");

    this->temp.setFont(font);
    this->temp.setRotation(90);
    this->temp.setString("Coming soon...");
    this->temp.setPosition(1720,80);
    this->temp.setCharacterSize(20);

    this->border.setPosition(1654,0);
    this->border.setSize(sf::Vector2f(196,300));
    this->border.setFillColor(sf::Color(255,255,255,5));
}

void VolumeWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    target.draw(this->temp,states);
}