#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP
#include"ActiveNote.hpp"
#include"Keyboard.hpp"
#include"Scale.hpp"
#include"Chord.hpp"
#include"Progression.hpp"
#include"VolumeControl.hpp"
#include<SFML/Graphics.hpp>

/*!
    \class ControlPanel
    \brief Class which accumulates all windows.

    One of the main classes. Sort of container for all windows in program.
*/

class ControlPanel :public sf::Drawable
{
private:
    Key* root_note;
    Keyboard* keyboard;
    
    Scale scale;

    ActiveNoteWindow root_window;
    ChordWindow chord_window;
    VolumeWindow volume_window;
    ScaleSFMLWindow scale_window;
    ProgressionWindow progression_window;

public:
    ControlPanel(sf::Font& ,Key*,Keyboard*);
    void set_root(Key*);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    void mouse_released();
private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif