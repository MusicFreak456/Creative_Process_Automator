#ifndef PROGRESSION_HPP
#define PROGRESSION_HPP
#include<SFML/Graphics.hpp>

class ProgressionWindow :public  sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::Text title;
    sf::Text temp;
public:
    ProgressionWindow(sf::Font&);
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif