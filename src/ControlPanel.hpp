#ifndef CONTROLPANEL_HPP
#define CONTROLPANEL_HPP
#include"ActiveNote.hpp"
#include"Keyboard.hpp"
#include"Scale.hpp"
#include"Chord.hpp"
#include"Progression.hpp"
#include"VolumeControl.hpp"
#include"Strategy.hpp"
#include<SFML/Graphics.hpp>

/*!
    \class ControlPanel
    \brief Class which accumulates all windows.

    One of the main classes. Sort of container for all windows and objects in program.
*/

class ControlPanel :public sf::Drawable, public IClickableSFML
{
private:
    Key* root_note;
    Keyboard* keyboard;

    Scale scale;
    Chords chords;
    VolumeControl vol_ctrl;

    ActiveNoteSFMLWindow root_window;
    ChordsSFMLWindow chord_window;
    VolumeSFMLWindow volume_window;
    ScaleSFMLWindow scale_window;
    ProgressionWindow progression_window; //Work in progress

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