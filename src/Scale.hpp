#ifndef SCALE_HPP
#define SCALE_HPP
#include<SFML/Graphics.hpp>
#include"Keyboard.hpp"
#include<vector>
#include<iostream>
#include"CheckBox.hpp"

using namespace std;

class Scale
{
private:
    vector<Key*> notes;

    Keyboard * keyboard;
    Key * root_key;
    
public:
    Scale(Keyboard *, Key *);
    string generate_scale();
    vector<Key *> get_vector_of_notes();
    string set_title();
    string change_root(Key*);
    void light_up();
    void dark_down();

};

class ScaleWindow :public sf::Drawable
{
private:
    Scale scale;

    sf::Text title;
    sf::Text string_repr;

    sf::RectangleShape border;

    CheckBox ch_box;

    bool show_scale;

    void set_title();
public:
    ScaleWindow(Keyboard *, Key*, sf::Font&);
    vector<Key *> get_vector_of_notes();
    void change_root(Key*);
    void light_up();
    void dark_down();
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif