#ifndef SCALE_HPP
#define SCALE_HPP
#include<SFML/Graphics.hpp>
#include"Keyboard.hpp"
#include<vector>
#include<iostream>
#include"CheckBox.hpp"

using namespace std;

class ScaleWindow :public sf::Drawable
{
public:
    vector<Key*> notes;
private:
    sf::RectangleShape border;

    Keyboard * keyboard;
    Key * root_key;

    sf::Text title;
    sf::Text string_repr;

    CheckBox ch_box;

    bool show_scale;

    void generate_scale();
    void set_title();
public:
    ScaleWindow(Keyboard *, Key*, sf::Font&);
    void change_root(Key*);
    void light_up();
    void dark_down();
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif