#ifndef KEY_HPP
#define KEY_HPP
#include<SFML/Graphics.hpp>

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
    bool root;
protected:
    Key();
public:
    virtual string get_note();
    virtual float get_value();
    virtual void set_note(string);
    virtual void set_value(float);
    virtual void in_scale()=0;
    virtual void in_chord()=0;
    virtual void highlight()= 0;
    virtual void reset_color();
    virtual void activate()=0;
    virtual void deactivate()=0;
    virtual void deactivate_chord();
    virtual void deactivate_scale();
    virtual void set_root();
    virtual void unset_root();
    virtual bool is_root();
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