#ifndef ACTIVENOTEBRACKET_HPP
#define ACTIVENOTEBRACKET_HPP
#include<SFML/Graphics.hpp>

using namespace std;

/*!
    \class ActiveNoteSFMLWindow
    \brief Maneges displaying current active note.
*/

class ActiveNoteSFMLWindow :public sf::Drawable
{
private:
    sf::Text title;
    sf::Text note;
    sf::RectangleShape rect;
private:
    void change_string_pos(int,int);
    void reset_string_pos();
public:
    ActiveNoteSFMLWindow(sf::Font&,string);

    void set_note(string);

private:
    void draw(sf::RenderTarget&,sf::RenderStates) const;

};

#endif