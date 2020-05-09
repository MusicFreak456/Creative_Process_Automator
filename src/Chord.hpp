#ifndef CHORD_HPP
#define CHORD_HPP
#include<cstdlib>
#include<vector>

#include<SFML/Graphics.hpp>
#include"Keyboard.hpp"
#include"Scale.hpp"

using namespace std;

class Chord :public sf::Drawable
{
protected:
    sf::RectangleShape border;
    vector<Key*> keys;
public:
    Chord(int, int);
    virtual void generate(Key* start_key) =0;
protected:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

class MajorChord :public Chord
{
public:
    MajorChord(int,int);
    virtual void generate(Key*);
};

class MinorChord :public Chord
{
public:
    MinorChord(int,int);
    virtual void generate(Key*);
};


class ChordBracket :public sf::Drawable
{
private:
    sf::RectangleShape border;
    sf::Text title;

    ScaleBracket * scale;
    Keyboard * keyboard;
    
    vector<Chord*> chords;
public:
    ChordBracket(ScaleBracket*, Keyboard*, sf::Font&);
    void move_position(int,int);
private:
    void generate_chords();
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
};

#endif