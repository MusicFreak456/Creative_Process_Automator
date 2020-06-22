#include"ActiveNote.hpp"

ActiveNoteSFMLWindow::ActiveNoteSFMLWindow(sf::Font& font,string note)
{
    this->title.setString("Key");
    this->note.setString(note);
    this->title.setFont(font);
    this->note.setFont(font);
    this->title.setPosition(100,30);
    this->note.setPosition(95,90);
    this->title.setCharacterSize(50);
    this->note.setCharacterSize(130);

    this->rect.setSize(sf::Vector2f(300,300));
    this->rect.setFillColor(sf::Color(255,255,255,10));
}

void ActiveNoteSFMLWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->rect);
    target.draw(this->note);
    target.draw(this->title);
}

void ActiveNoteSFMLWindow::change_string_pos(int x,int y)
{
    this->note.setPosition(x,y);
}
void ActiveNoteSFMLWindow::reset_string_pos()
{
    this->note.setPosition(95,90);
}

void ActiveNoteSFMLWindow::set_note(string note)
{
    this->note.setString(note);
    if(note.length() == 2)
    {
        this->change_string_pos(65,90);
    }
    else this->reset_string_pos();
}