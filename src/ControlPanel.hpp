#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP
#include"ActiveNoteBracket.hpp"
#include"Keyboard.hpp"
#include"Scale.hpp"
#include"Chord.hpp"
#include"VolumeControl.hpp"
#include<SFML/Graphics.hpp>

class ControlPanel :public sf::Drawable
{
private:
    ActiveNoteBracket root_bracket;
    ChordBracket chord_bracket;
    VolumeBracket volume_bracket;
    ScaleBracket scale;
    Key * root_note;
    Keyboard * keyboard;

public:
    ControlPanel(sf::Font& ,Key*,Keyboard*);
    void set_root(Key*);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif