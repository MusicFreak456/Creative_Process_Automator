#ifndef CHORD_HPP
#define CHORD_HPP
#include<cstdlib>
#include<vector>

#include<SFML/Graphics.hpp>
#include"Keyboard.hpp"
#include"Scale.hpp"
#include"ClickableBox.hpp"
#include"Strategy.hpp"

using namespace std;

/*!
    \class NoteSFMLTile
    \brief Small tile for displaying one of the notes.

    Small tile created with given string. Used for displaynig series of notes from chord.
*/

class NoteSFMLTile :public sf::Drawable
{
public:
    static const int width = 55;
    static const int height = 36;
private:
    sf::RectangleShape border;

    sf::Text text;
public:
    NoteSFMLTile(sf::Font&,string,int,int,bool);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

/*!
    \class Chord
    \brief Main abstract class for chords.

    Implements most of the chord functionalities, except for generating, which is specific to different kinds of chords.
*/

class Chord
{
public:
protected:
    int posx;
    int posy;

    vector<Key*> keys;

    string name;
    Key * start_key;

public:
    Chord(string,Key*,Keyboard*,int, int);
    virtual void generate(Key*,Keyboard*,int,int) =0;
    void play();
    bool is_playing();
    vector<Key*> get_vector_of_keys();
    string get_name();
    int get_posx();
    int get_posy();
};

/*!
    \class ChordSFML
    \brief Maneges displaying single chord
*/

class ChordSFML :public sf::Drawable, public IClickableSFML
{
private:
    sf::RectangleShape border;
    CheckBox show_check_box;
    PlayBox play_box;
    vector<NoteSFMLTile> tiles;
    vector<ChordSFML *>& all_chords;

    Chord& chord;

    bool show_chord;
    bool playing;
public:
    ChordSFML(Chord&, sf::Font&,vector<ChordSFML*>&, int, int);
    void light_up();
    void dark_down();
    bool is_shown();
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    void change_root();
protected:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

/*!
    \class MajorChord
    \brief Class for major chords.

    Implements generating major chords.
*/

class MajorChord :public Chord
{
public:
    MajorChord(string,Key*,Keyboard*,int,int);
    virtual void generate(Key*,Keyboard*,int,int);
};

/*!
    \class MinorChord
    \brief Class for minor chords.

    Implements generating minor chords.
*/

class MinorChord :public Chord
{
public:
    MinorChord(string,Key*,Keyboard*,int,int);
    virtual void generate(Key*,Keyboard*,int,int);
};

/*!
    \class Chords
    \brief Collection of all chords
*/


class Chords 
{
private:
    Scale * scale;
    Keyboard * keyboard;
    
    vector<Chord*> chords;
public:
    Chords(Keyboard*,Scale*);
    void set_scale(Scale*);
    vector<Chord*> get_vector_of_all_chords();
    
private:
    void generate_chords(Scale*);
};

/*!
    \class ChordsSFMLWindow
    \brief Responsible for displaying table of chords
*/

class ChordsSFMLWindow :public sf::Drawable, public IClickableSFML
{
private:
    sf::RectangleShape border;
    sf::Text title;
    sf::Font font;

    vector<ChordSFML*> vector_of_sfml_chords;

    Chords& chords;
public:
    ChordsSFMLWindow(Chords&, sf::Font&);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    void set_scale(Scale*);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};


#endif