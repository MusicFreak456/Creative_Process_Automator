#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;

class CheckBox :public sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::RectangleShape ch_box;
    sf::Text title;

    bool checked;
public:
    CheckBox(string,sf::Font&);

    void move_position(float x, float y);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    bool is_checked();
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif