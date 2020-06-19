#ifndef VOLUMECONTROL_HPP
#define VOLUMECONTROL_HPP
#include<SFML/Graphics.hpp>
#include<iostream>

#include"Slider.hpp"
#include"Keyboard.hpp"

using namespace std;

/*!
    \class VolumeWindow
    \brief Creates user interface for controling sound volume.
*/

class VolumeWindow :public sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::Text title;
    sf::Text proc_value;
    VerticalSlider slider;

    int curr_value;
    Keyboard * keyboard;
    
    void set_value_str();
public:
    VolumeWindow(sf::Font&, Keyboard*, int);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    void mouse_released();
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};


#endif