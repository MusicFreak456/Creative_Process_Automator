#include"Scale.hpp"

ScaleWindow::ScaleWindow(Keyboard * keyboard, Key * root_key ,sf::Font & font): keyboard(keyboard), root_key(root_key), ch_box("Show scale",font)
{
    this->notes.push_back(this->root_key);

    this->show_scale = false;

    this->ch_box.move_position(950,0);

    this->title.setFont(font);
    this->set_title();
    this->title.setPosition(304,0);
    this->title.setCharacterSize(24);

    this->string_repr.setFont(font);
    this->string_repr.setPosition(340,50);
    this->string_repr.setCharacterSize(40);

    this->generate_scale();
    
    this->border.setPosition(304,0);
    this->border.setSize(sf::Vector2f(796,146));
    this->border.setFillColor(sf::Color(255,255,255,5));
}

void ScaleWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    target.draw(this->string_repr,states);
    target.draw(this->ch_box,states);
}

void ScaleWindow::set_title()
{
    this->title.setString(root_key->get_note() + " major scale: ");
}

void ScaleWindow::generate_scale()
{
    int root_value = root_key->get_value();
    if(root_value < Keyboard::number_of_keys - 1)this->notes.push_back( keyboard->find_key(root_value + 2));
    if(root_value < Keyboard::number_of_keys - 3)this->notes.push_back( keyboard->find_key(root_value + 4));
    if(root_value < Keyboard::number_of_keys - 4)this->notes.push_back( keyboard->find_key(root_value + 5));
    if(root_value < Keyboard::number_of_keys - 6)this->notes.push_back( keyboard->find_key(root_value + 7));
    if(root_value < Keyboard::number_of_keys - 8)this->notes.push_back( keyboard->find_key(root_value + 9));
    if(root_value < Keyboard::number_of_keys - 10)this->notes.push_back( keyboard->find_key(root_value + 11));

    string repr = "";
    for(Key * k : notes)
    {
        repr += k->get_note() + "   ";
    }
    this->string_repr.setString(repr);

    this->set_title();
}

void ScaleWindow::change_root(Key* new_root)
{
    this->dark_down();
    this->root_key = new_root;
    this->root_key->activate();
    this->notes.clear();
    this->notes.push_back(root_key);
    this->generate_scale();
    if(this->show_scale)
    {
        this->light_up();
    }
}

void ScaleWindow::light_up()
{
    for(Key * k : notes)
    {
        if(k!=this->root_key)k->in_scale();
        else k->activate();
    }
}
void ScaleWindow::dark_down()
{
    for(Key * k : notes)
    {
        if(k!=root_key)
        k->deactivate_scale();
    }
}

void ScaleWindow::hovers_detection(sf::Vector2f mouse_coords)
{
    this->ch_box.hovers_detection(mouse_coords);
}
void ScaleWindow::mouse_pressed(sf::Vector2f mouse_coords)
{
    this->ch_box.mouse_pressed(mouse_coords);
    if(this->ch_box.is_checked() && !this->show_scale)
    {
        this->show_scale = true;
        this->light_up();
    }
    else if (!this->ch_box.is_checked() && this->show_scale)
    {
        this->show_scale = false;
        this->dark_down();
    }
}

vector<Key *> ScaleWindow::get_vector_of_notes()
{
    return this->notes;
}