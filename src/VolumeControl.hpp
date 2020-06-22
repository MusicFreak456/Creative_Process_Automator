#ifndef VOLUMECONTROL_HPP
#define VOLUMECONTROL_HPP
#include<SFML/Graphics.hpp>
#include<iostream>

#include"Slider.hpp"
#include"Keyboard.hpp"

using namespace std;

/*!
    \class VolumeControl
    \brief Implementation of volume control
*/

class VolumeControl
{
private:
    int current_value;
    string string_repr;

    Keyboard * keyboard;
public:
    VolumeControl(Keyboard*);
    bool change_volume(int);
    string create_string_repr();
};

/*!
    \class VolumeSFMLWindow
    \brief Creates user interface for controling sound volume.
*/

class VolumeSFMLWindow :public sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::Text title;
    sf::Text proc_value;
    VerticalSlider slider;

    VolumeControl& vol_ctrl;
    
    void set_value_str();
public:
    VolumeSFMLWindow(sf::Font&, VolumeControl&);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    void mouse_released();
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};


#endif