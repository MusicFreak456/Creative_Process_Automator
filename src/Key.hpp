#ifndef KEY_HPP
#define KEY_HPP
#include<SFML/Graphics.hpp>

using namespace std;

class WhiteKey :public sf::RectangleShape
{
protected:
    string note;
    int int_value;
private:
    const int height;
    const int width;
public:
    WhiteKey();
    void set_note(string);
    string get_note();
    void set_value(int);
    int get_value();
    int get_height();
};

class BlackKey :public WhiteKey
{
private:
    const int height;
    const int width;
public:
    BlackKey();
};


#endif