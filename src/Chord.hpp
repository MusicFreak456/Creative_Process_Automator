#ifndef CHORD_HPP
#define CHORD_HPP
#include<cstdlib>
#include<vector>

#include<SFML/Graphics.hpp>
#include"Keyboard.hpp"
#include"Scale.hpp"
#include"CheckBox.hpp"

using namespace std;

class ChordWindowTile :public sf::Drawable
{
public:
    static const int width = 55;
    static const int height = 36;
private:
    sf::RectangleShape border;

    sf::Text text;
public:
    ChordWindowTile(sf::Font&,string,int,int,bool);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

class Chord :public sf::Drawable
{
protected:
    sf::RectangleShape border;
    CheckBox show_check_box;

    vector<Key*> keys;
    vector<ChordWindowTile> tiles;

    string name;
    Key * start_key;

    bool show_chord;
public:
    Chord(sf::Font&,string,Key*,Keyboard*,int, int);
    void light_up();
    void dark_down();
    bool is_shown();
    void change_root();
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
    virtual void generate(sf::Font&,Key*,Keyboard*,int,int) =0;
protected:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

class MajorChord :public Chord
{
public:
    MajorChord(sf::Font&,string,Key*,Keyboard*,int,int);
    virtual void generate(sf::Font&,Key*,Keyboard*,int,int);
};

class MinorChord :public Chord
{
public:
    MinorChord(sf::Font&,string,Key*,Keyboard*,int,int);
    virtual void generate(sf::Font&,Key*,Keyboard*,int,int);
};


class ChordWindow :public sf::Drawable
{
private:

    sf::RectangleShape border;
    sf::Text title;
    sf::Font font;

    ScaleWindow * scale;
    Keyboard * keyboard;
    
    vector<Chord*> chords;
public:
    ChordWindow(Keyboard*, sf::Font&);
    void move_position(int,int);
    void set_scale(ScaleWindow*);
    void hovers_detection(sf::Vector2f);
    void mouse_pressed(sf::Vector2f);
private:
    void generate_chords(sf::Font&, ScaleWindow*);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};



#endif