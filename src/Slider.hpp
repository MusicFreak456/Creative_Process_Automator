#ifndef SLIDER_HPP
#define SLIDER_HPP
#include<SFML/Graphics.hpp>

class VerticalSlider :public sf::Drawable
{
private:
    sf::RectangleShape path;
    sf::RectangleShape slider;
    bool is_track;
    sf::Vector2i mouse_pos;

    void track();
public:
    VerticalSlider(int, int, int, sf::Font&);
    int move_slider(int);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif