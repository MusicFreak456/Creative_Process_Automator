#include"VolumeControl.hpp"

VolumeWindow::VolumeWindow(sf::Font& font, Keyboard* keyboard, int value):
slider(1703,50,175,font),
value(value),
keyboard(keyboard)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1660,0);
    this->title.setString("volume");

    this->border.setPosition(1654,0);
    this->border.setSize(sf::Vector2f(196,300));
    this->border.setFillColor(sf::Color(255,255,255,5));

    this->keyboard->change_volume(this->value);
}

void VolumeWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    target.draw(this->slider,states);
}

void VolumeWindow::hovers_detection(sf::Vector2f mouse_pos)
{
    this->slider.hovers_detection(mouse_pos);
}

void VolumeWindow::mouse_pressed(sf::Vector2f mouse_pos)
{
    this->slider.mouse_pressed(mouse_pos);
}

void VolumeWindow::mouse_released()
{
    this->slider.mouse_released();
}
