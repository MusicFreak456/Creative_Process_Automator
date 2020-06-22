#include"VolumeControl.hpp"

VolumeSFMLWindow::VolumeSFMLWindow(sf::Font& font, VolumeControl& vol_ctrl):
vol_ctrl(vol_ctrl),
slider(1703,50,185,font)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1660,0);
    this->title.setString("volume");

    this->border.setPosition(1654,0);
    this->border.setSize(sf::Vector2f(196,300));
    this->border.setFillColor(sf::Color(255,255,255,5));

    this->proc_value.setFont(font);
    this->proc_value.setCharacterSize(30);
    this->proc_value.setFillColor(sf::Color(255,255,255));
    this->proc_value.setPosition(1680,250);
    this->set_value_str();
}

VolumeControl::VolumeControl(Keyboard* keyboard):
keyboard(keyboard),
current_value(50)
{
    keyboard->change_volume(this->current_value);
}

string VolumeControl::create_string_repr()
{
    return std::to_string(this->current_value) + "%";
}

bool VolumeControl::change_volume(int new_val)
{
    if(current_value!= new_val)
    {
        keyboard->change_volume(new_val);
        this->current_value = new_val;
        return true;
    }

    return false;
}

void VolumeSFMLWindow::set_value_str()
{
    this->proc_value.setString(this->vol_ctrl.create_string_repr());
}

void VolumeSFMLWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    target.draw(this->slider,states);
    target.draw(this->proc_value,states);
}

void VolumeSFMLWindow::hovers_detection(sf::Vector2f mouse_pos)
{
    this->slider.hovers_detection(mouse_pos);
    int new_val = this->slider.get_value();
    if(this->vol_ctrl.change_volume(new_val))
    {
        this->set_value_str();
    }
}

void VolumeSFMLWindow::mouse_pressed(sf::Vector2f mouse_pos)
{
    this->slider.mouse_pressed(mouse_pos);
    int new_val = this->slider.get_value();
    if(this->vol_ctrl.change_volume(new_val))
    {
        this->set_value_str();
    }
}

void VolumeSFMLWindow::mouse_released()
{
    this->slider.mouse_released();
    int new_val = this->slider.get_value();
    if(this->vol_ctrl.change_volume(new_val))
    {
        this->set_value_str();
    }
}
