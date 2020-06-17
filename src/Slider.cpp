#include"Slider.hpp"

void VerticalSlider::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->path,states);
    target.draw(this->slider,states);
}

VerticalSlider::VerticalSlider(int x, int y, int height, sf::Font& font):
value(50),
is_tracked(false),
height(height),
mouse_pos(sf::Mouse::getPosition())
{
    this->path.setPosition(x,y);
    this->path.setSize(sf::Vector2f(8, height));
    this->path.setFillColor(sf::Color(255,255,255,60));

    this->slider.setSize(sf::Vector2f(16,8));
    this->slider.setFillColor(sf::Color(255,255,255,200));
    this->slider.setPosition(x-4,y+height/2-4);
}

void VerticalSlider::move_slider(int value)
{

    this->slider.move(sf::Vector2f(0,value));
    double step = 100.0/this->height;
    int y_sl = this->slider.getPosition().y;
    int y_beg = this->path.getPosition().y;
    int diff = y_sl - y_beg;
    this->value = 100 - diff * step;
    if(this->value >= 100)
    {
        this->value = 100;
        this->slider.setPosition(this->slider.getPosition().x, this->path.getPosition().y);
    }
    else if(this->value <= 0)
    {
        this->value = 0;
        this->slider.setPosition(this->slider.getPosition().x, this->path.getPosition().y + this->height);
    }

}

void VerticalSlider::track()
{
    sf::Vector2i new_mouse_pos = sf::Mouse::getPosition();
    int new_y = new_mouse_pos.y;
    int last_y = this->mouse_pos.y;
    if(new_y != last_y)
    {
        this->move_slider(new_y-last_y);
        this->mouse_pos = new_mouse_pos;
    }
}

void VerticalSlider::hovers_detection(sf::Vector2f mouse_pos)
{
    if(this->is_tracked)this->track();
}

void VerticalSlider::mouse_pressed(sf::Vector2f mouse_coords)
{
    sf::FloatRect bounds = this->slider.getGlobalBounds();
    if(bounds.contains(mouse_coords))
    {
        this->mouse_pos = sf::Mouse::getPosition();
        this->is_tracked = true;
        return;
    }
    bounds = this->path.getGlobalBounds();
    if(bounds.contains(mouse_coords))
    {
        this->move_slider(mouse_coords.y - this->slider.getPosition().y);
    }
}

void VerticalSlider::mouse_released()
{
    this->is_tracked = false;
}

int VerticalSlider::get_value()
{
    return this->value;
}