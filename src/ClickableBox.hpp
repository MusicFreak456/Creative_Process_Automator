#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP
#include<SFML/Graphics.hpp>
#include<iostream>

#include"Strategy.hpp"

using namespace std;

/*!
    \class CheckBox
    \brief Menages all checkboxes.

    Creates checkbox using given string and font.
*/

class CheckBox :public sf::Drawable, public IClickableSFML
{
protected:
    sf::RectangleShape border;
    sf::RectangleShape ch_box;
    sf::Text title;

    bool checked;
public:
    CheckBox(string,sf::Font&);

    void move_position(float x, float y);
    void change_size (int, int);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    bool is_checked();
    void uncheck();
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

class PlayBox :public CheckBox
{
private:
    sf::CircleShape triangle;
public:
    PlayBox(string,sf::Font&);
    void move_position(float x, float y);
    void mouse_pressed(sf::Vector2f);
    void uncheck();
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif