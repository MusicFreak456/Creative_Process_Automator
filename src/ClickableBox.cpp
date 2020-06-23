#include"ClickableBox.hpp"

CheckBox::CheckBox(string title, sf::Font& font)
{
    this->checked = false;
    this->title.setFont(font);
    this->title.setString(title);
    this->title.setCharacterSize(19);
    this->title.setPosition(28,2);
    
    this->border.setSize(sf::Vector2f(150,30));
    this->border.setFillColor(sf::Color(255,255,255,30));

    this->ch_box.setFillColor(sf::Color::White);
    this->ch_box.setSize(sf::Vector2f(10,10));
    this->ch_box.setPosition(10,10);
}

void CheckBox::change_size(int width,int height)
{
    this->border.setSize(sf::Vector2f(width,height));
}

void CheckBox::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->ch_box,states);
    target.draw(this->title,states);
}

void CheckBox::move_position(float x, float y)
{
    this->border.setPosition(this->border.getPosition().x+x , this->border.getPosition().y+y );
    this->ch_box.setPosition(this->ch_box.getPosition().x+x , this->ch_box.getPosition().y+y );
    this->title.setPosition(this->title.getPosition().x+x , this->title.getPosition().y+y );
}

void CheckBox::hovers_detection(sf::Vector2f mouse_coords)
{
    sf::FloatRect bounds = this->border.getGlobalBounds();
    if(bounds.contains(mouse_coords))
    {
        this->border.setFillColor(sf::Color(255,255,255,50));
    }
    else
    {
        this->border.setFillColor(sf::Color(255,255,255,30));
    }
    
}

void CheckBox::mouse_pressed(sf::Vector2f mouse_coords)
{
    sf::FloatRect bounds = this->border.getGlobalBounds();
    if(bounds.contains(mouse_coords))
    {
        this->checked = !this->checked;

        if(this->checked)this->ch_box.setFillColor(sf::Color::Black);
        else this->ch_box.setFillColor(sf::Color::White);
    }
}

bool CheckBox::is_checked()
{
    return this->checked;
}

void CheckBox::uncheck()
{
    this->checked = false;
    this->ch_box.setFillColor(sf::Color::White);
}

PlayBox::PlayBox(string label,sf::Font& font):
CheckBox(label,font),
triangle(8,3)
{
    this->triangle.rotate(90);

    this->triangle.setPosition(22,8);
}

void PlayBox::move_position(float x, float y)
{
    this->border.setPosition(this->border.getPosition().x+x , this->border.getPosition().y+y );
    this->triangle.setPosition(this->triangle.getPosition().x+x , this->triangle.getPosition().y+y );
    this->title.setPosition(this->title.getPosition().x+x , this->title.getPosition().y+y );
}

void PlayBox::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->triangle,states);
    target.draw(this->title,states);
}

void PlayBox::mouse_pressed(sf::Vector2f mouse_coords)
{
    sf::FloatRect bounds = this->border.getGlobalBounds();
    if(bounds.contains(mouse_coords))
    {
        this->checked = !this->checked;

        if(this->checked)this->triangle.setFillColor(sf::Color::Black);
        else this->triangle.setFillColor(sf::Color::White);
    }
}

void PlayBox::uncheck()
{
    this->checked = false;
    this->triangle.setFillColor(sf::Color::White);
}