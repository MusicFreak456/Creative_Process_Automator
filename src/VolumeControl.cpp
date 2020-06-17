#include"VolumeControl.hpp"

VolumeWindow::VolumeWindow(sf::Font& font, Keyboard* keyboard, int value):
slider(1703,50,185,font),
curr_value(50),
keyboard(keyboard)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1660,0);
    this->title.setString("volume");

    this->border.setPosition(1654,0);
    this->border.setSize(sf::Vector2f(196,300));
    this->border.setFillColor(sf::Color(255,255,255,5));

    this->keyboard->change_volume(this->curr_value);

    this->proc_value.setFont(font);
    this->proc_value.setCharacterSize(30);
    this->proc_value.setFillColor(sf::Color(255,255,255));
    this->proc_value.setPosition(1680,250);
    this->set_value_str();
}

void VolumeWindow::set_value_str()
{
    this->proc_value.setString(std::to_string(this->curr_value) + "%");
}

void VolumeWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    target.draw(this->slider,states);
    target.draw(this->proc_value,states);
}

void VolumeWindow::hovers_detection(sf::Vector2f mouse_pos)
{
    int prev_val = this->curr_value;
    this->slider.hovers_detection(mouse_pos);
    this->curr_value = this->slider.get_value();
    if(curr_value!= prev_val) this->set_value_str();
}

void VolumeWindow::mouse_pressed(sf::Vector2f mouse_pos)
{
    this->slider.mouse_pressed(mouse_pos);
}

void VolumeWindow::mouse_released()
{

    this->slider.mouse_released();
}
