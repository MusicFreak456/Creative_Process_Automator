#include"ControlPanel.hpp"

ControlPanel::ControlPanel(sf::Font& font, Key* root_note, Keyboard* keyboard): 
root_note(root_note), 
root_bracket(ActiveNoteWindow(font,root_note->get_note())),
keyboard(keyboard),
scale(keyboard,root_note,font),
chord_bracket(keyboard,font),
volume_bracket(font)
{
    this->chord_bracket.set_scale(&(this->scale));
    this->root_note->set_root();
}

void ControlPanel::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->root_bracket);
    target.draw(this->scale);
    target.draw(this->chord_bracket);
    target.draw(this->volume_bracket);
}

void ControlPanel::set_root(Key* root_note)
{
    this->root_note->unset_root();
    this->root_note = root_note;
    this->root_note->set_root();
    this->root_bracket.set_note(root_note->get_note());
    this->scale.change_root(root_note);
    this->chord_bracket.set_scale(&(this->scale));
}

void ControlPanel::hovers_detection(sf::Vector2f mouse_coords)
{
    this->scale.hovers_detection(mouse_coords);
    this->chord_bracket.hovers_detection(mouse_coords);
}

void ControlPanel::mouse_pressed(sf::Vector2f mouse_coords)
{
    this->scale.mouse_pressed(mouse_coords);
    this->chord_bracket.mouse_pressed(mouse_coords);
}
