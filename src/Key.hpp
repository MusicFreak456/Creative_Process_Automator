#ifndef KEY_HPP
#define KEY_HPP
#include<SFML/Graphics.hpp>
#include"Highlightable.hpp"

using namespace std;

class Key :public sf::RectangleShape,public IHighlightable
{
protected:
    string note;
    float value;
    bool active;
};

class WhiteKey :public Key
{

public:
    static const int Height = 200;
    static const int Width = 32; 
public:
    WhiteKey();
    void set_note(string);
    string get_note();
    void set_value(float);
    float get_value();
    void reset_color();
    void highlight();
};

class BlackKey :public WhiteKey
{
public:
    static const int Height = 120;
    static const int Width = 20;
public:
    BlackKey();
    void reset_color();
    void highlight();
};


#endif