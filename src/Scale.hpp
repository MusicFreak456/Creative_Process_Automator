#ifndef SCALE_HPP
#define SCALE_HPP
#include<SFML/Graphics.hpp>
#include"Keyboard.hpp"
#include<vector>
#include<iostream>
#include"CheckBox.hpp"
#include"Strategy.hpp"

using namespace std;

/*!
    \class Scale
    \brief Implements scale functionalities.
*/

class Scale
{
private:
    vector<Key*> notes;

    Keyboard * keyboard;
    Key * root_key;

    string str_repr;
    
public:
    Scale(Keyboard *, Key *);
    void generate_scale();
    vector<Key *> get_vector_of_notes();
    Key * get_root_key();
    string set_title();
    string get_string_repr();
    void change_root(Key*);
};

/*!
    \class ScaleSFMLWindow
    \brief Menages displaying scale
*/

class ScaleSFMLWindow :public sf::Drawable, public IClickableSFML
{
private:
    Scale& scale;

    sf::Text title;
    sf::Text string_repr;

    sf::RectangleShape border;

    CheckBox ch_box;

    bool show_scale;

    void set_title();
public:
    ScaleSFMLWindow(Scale&, sf::Font&);
    void change_root(Key*);
    void light_up();
    void dark_down();
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif