#include"VolumeControl.hpp"

VolumeBracket::VolumeBracket(sf::Font& font)
{
    this->border.setPosition(1654,0);
    this->border.setSize(sf::Vector2f(196,300));
    this->border.setFillColor(sf::Color(255,255,255,5));
}

void VolumeBracket::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
}