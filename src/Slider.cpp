#include"Slider.hpp"

void VerticalSlider::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->path,states);
    target.draw(this->slider,states);
}

VerticalSlider::VerticalSlider(int x, int y, int height, sf::Font& font):
is_track(false),
mouse_pos(0,0)
{
    this->path.setPosition(x,y);
    this->path.setSize(sf::Vector2f(8, height));
    this->path.setFillColor(sf::Color(255,255,255,60));

    this->slider.setSize(sf::Vector2f(16,8));
    this->slider.setFillColor(sf::Color(255,255,255));
    this->slider.setPosition(x-4,y+height/2-4);
}

int VerticalSlider::move_slider(int value)
{
    
}

void VerticalSlider::track()
{
    sf::Vector2i new_mouse_pos = sf::Mouse::getPosition();
}