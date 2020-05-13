#ifndef KEY_HPP
#define KEY_HPP
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

using namespace std;

class Key :public sf::RectangleShape
{
protected:
    string note;
    float value;
    bool active;
    bool scale;
    bool chord;
    sf::Color default_color;
    sf::SoundBuffer sound_buffer;
    sf::Sound sound;
    bool root;
protected:
    Key();
public:
    virtual string get_note();
    float get_value();
    void set_note(string);
    void set_value(float);
    void reset_color();
    void deactivate_chord();
    void deactivate_scale();
    void set_root();
    void unset_root();
    bool is_root();
    void play();
    virtual void highlight()= 0;
    virtual void in_chord()=0;
    virtual void in_scale()=0;
    virtual void activate()=0;
    virtual void deactivate()=0;
};

class WhiteKey :public Key
{
public:
    static const int Height = 200;
    static const int Width = 32;
public:
    WhiteKey();
    void highlight();
    void activate();
    void deactivate();
    void in_scale();
    void in_chord();
};

class BlackKey :public Key
{
public:
    static const int Height = 120;
    static const int Width = 20;
public:
    BlackKey();
    void highlight();
    void activate();
    void deactivate();
    void in_scale();
    void in_chord();
};


#endif