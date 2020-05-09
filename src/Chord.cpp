#include"Chord.hpp"

ChordBracket::ChordBracket(Key * root, sf::Font& font): root(root)
{
    this->border.setPosition(1104,0);
    this->border.setSize(sf::Vector2f(546,300));
    this->border.setFillColor(sf::Color(255,255,255,10));
}

void ChordBracket::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
}

