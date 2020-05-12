#ifndef VOLUMECONTROL_HPP
#define VOLUMECONTROL_HPP
#include<SFML/Graphics.hpp>

using namespace std;

class VolumeWindow :public sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::Text title;
public:
    VolumeWindow(sf::Font&);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};


#endif