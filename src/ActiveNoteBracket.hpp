#ifndef ACTIVENOTEBRACKET_HPP
#define ACTIVENOTEBRACKET_HPP
#include<SFML/Graphics.hpp>


using namespace std;

class ActiveNoteBracket :public sf::Drawable
{
private:
    sf::Text title;
    sf::Text note;
    sf::RectangleShape rect;
private:
    void change_string_pos(int,int);
    void reset_string_pos();
public:
    ActiveNoteBracket(sf::Font&,string);

    void set_note(string);

private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;

};

#endif