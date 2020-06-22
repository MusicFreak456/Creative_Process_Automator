#ifndef STRATEGY_HPP
#define STRATEGY_HPP
#include<SFML/System.hpp>

/*!
    \class IClickableSFML
    \brief Intarface for classes that contain clickable objects.
*/

class IClickableSFML
{
    virtual void hovers_detection(sf::Vector2f)=0;
    virtual void mouse_pressed(sf::Vector2f)=0;
};

#endif