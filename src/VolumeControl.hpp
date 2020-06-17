#ifndef VOLUMECONTROL_HPP
#define VOLUMECONTROL_HPP
#include<SFML/Graphics.hpp>

#include"Slider.hpp"
#include"Keyboard.hpp"

using namespace std;

class VolumeWindow :public sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::Text title;
    sf::Text proc_value;
    VerticalSlider slider;

    int value;
    Keyboard * keyboard;
    
public:
    VolumeWindow(sf::Font&, Keyboard*, int);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};


#endif