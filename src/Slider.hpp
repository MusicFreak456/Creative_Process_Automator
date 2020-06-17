#ifndef SLIDER_HPP
#define SLIDER_HPP
#include<SFML/Graphics.hpp>
#include<iostream>

class VerticalSlider :public sf::Drawable
{
private:

    sf::RectangleShape path;
    sf::RectangleShape slider;
    sf::Vector2i mouse_pos;

    bool is_tracked;
    int height;

    int value;

    void track();
public:
    VerticalSlider(int, int, int, sf::Font&);
    void move_slider(int);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    void mouse_released();
    int get_value();
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif