#include"ControlPanel.hpp"

ControlPanel::ControlPanel(sf::Font& font, Key* root_note, Keyboard* keyboard): 
root_note(root_note), 
root_window(ActiveNoteWindow(font,root_note->get_note())),
keyboard(keyboard),
scale_window(keyboard,root_note,font),
chord_window(keyboard,font),
volume_window(font,keyboard, 20),
progression_window(font)
{
    this->chord_window.set_scale(&(this->scale_window));
    this->root_note->set_root();
}

void ControlPanel::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->root_window,states);
    target.draw(this->scale_window,states);
    target.draw(this->progression_window,states);
    target.draw(this->chord_window,states);
    target.draw(this->volume_window,states);
}

void ControlPanel::set_root(Key* root_note)
{
    this->root_note->unset_root();
    this->root_note = root_note;
    this->root_note->set_root();
    this->root_note->play();
    this->root_window.set_note(root_note->get_note());
    this->scale_window.change_root(root_note);
    this->chord_window.set_scale(&(this->scale_window));
}

void ControlPanel::hovers_detection(sf::Vector2f mouse_coords)
{
    this->scale_window.hovers_detection(mouse_coords);
    this->chord_window.hovers_detection(mouse_coords);
}

void ControlPanel::mouse_pressed(sf::Vector2f mouse_coords)
{
    this->scale_window.mouse_pressed(mouse_coords);
    this->chord_window.mouse_pressed(mouse_coords);
}
