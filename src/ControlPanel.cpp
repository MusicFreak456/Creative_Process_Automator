#include"ControlPanel.hpp"

ControlPanel::ControlPanel(sf::Font& font, string root_note): root_note(root_note), root_bracket(ActiveNoteBracket(font,root_note)){}

void ControlPanel::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->root_bracket);
}

void ControlPanel::set_root(string root_note)
{
    this->root_note = root_note;
    this->root_bracket.set_note(root_note);
}
