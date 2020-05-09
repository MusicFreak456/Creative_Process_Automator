#ifndef CHORD_HPP
#define CHORD_HPP
#include<cstdlib>

#include<SFML/Graphics.hpp>
#include"Key.hpp"

class ChordBracket :public sf::Drawable
{
private:
    sf::RectangleShape border;
    Key * root;
public:
    ChordBracket(Key*, sf::Font&);
    void move_position(int,int);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif