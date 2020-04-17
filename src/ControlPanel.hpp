#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP
#include"ActiveNoteBracket.hpp"
#include<SFML/Graphics.hpp>

class ControlPanel :public sf::Drawable
{
private:
    ActiveNoteBracket root_bracket;
    string root_note;
public:
    ControlPanel(sf::Font& ,string);
    void set_root(string);
    
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif