#include"Scale.hpp"

ScaleSFMLWindow::ScaleSFMLWindow(Scale& scale ,sf::Font & font): 
scale(scale), 
ch_box("Show scale",font)
{
    this->ch_box.move_position(950,0);

    this->show_scale = false;

    this->title.setFont(font);
    this->title.setPosition(304,0);
    this->title.setCharacterSize(24);

    this->string_repr.setFont(font);
    this->string_repr.setPosition(340,50);
    this->string_repr.setCharacterSize(40);

    this->string_repr.setString(scale.get_string_repr());
    this->set_title();
    
    this->border.setPosition(304,0);
    this->border.setSize(sf::Vector2f(796,146));
    this->border.setFillColor(sf::Color(255,255,255,5));
}

Scale::Scale(Keyboard * keyboard, Key * root_key): keyboard(keyboard), root_key(root_key)
{
    this->notes.push_back(this->root_key);
    this->generate_scale();
}

void ScaleSFMLWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    target.draw(this->string_repr,states);
    target.draw(this->ch_box,states);
}

void ScaleSFMLWindow::set_title()
{
    this->title.setString(this->scale.set_title());
}

string Scale::set_title()
{
    return root_key->get_note() + " major scale: ";
}

void Scale::generate_scale()
{
    int root_value = root_key->get_value();
    if(root_value < Keyboard::number_of_keys - 1 )this->notes.push_back( keyboard->find_key(root_value + 2));
    if(root_value < Keyboard::number_of_keys - 3 )this->notes.push_back( keyboard->find_key(root_value + 4));
    if(root_value < Keyboard::number_of_keys - 4 )this->notes.push_back( keyboard->find_key(root_value + 5));
    if(root_value < Keyboard::number_of_keys - 6 )this->notes.push_back( keyboard->find_key(root_value + 7));
    if(root_value < Keyboard::number_of_keys - 8 )this->notes.push_back( keyboard->find_key(root_value + 9));
    if(root_value < Keyboard::number_of_keys - 10)this->notes.push_back( keyboard->find_key(root_value + 11));

    string repr = "";
    for(Key * k : notes)
    {
        repr += k->get_note() + "   ";
    }

    this->str_repr = repr;    
}

void ScaleSFMLWindow::change_root(Key* new_root)
{
    this->dark_down();
    scale.change_root(new_root);
    this->string_repr.setString(scale.get_string_repr());
    this->set_title();
    if(this->show_scale)
    {
        this->light_up();
    }
}

void Scale::change_root(Key* new_root)
{
    this->root_key = new_root;
    this->root_key->activate();
    this->notes.clear();
    this->notes.push_back(root_key);
    this->generate_scale();
}

string Scale::get_string_repr()
{
    return this->str_repr;
}

void ScaleSFMLWindow::light_up()
{
    vector<Key *> vector_of_notes  = this->scale.get_vector_of_notes();
    Key * root = this->scale.get_root_key();

    for(Key * k : vector_of_notes)
    {
        if(k!=root)k->in_scale();
        else k->activate();
    }
}

void ScaleSFMLWindow::dark_down()
{
    vector<Key *> vector_of_notes  = this->scale.get_vector_of_notes();
    Key * root = this->scale.get_root_key();

    for(Key * k : vector_of_notes)
    {
        if(k!=root)
        k->deactivate_scale();
    }

}

void ScaleSFMLWindow::hovers_detection(sf::Vector2f mouse_coords)
{
    this->ch_box.hovers_detection(mouse_coords);
}
void ScaleSFMLWindow::mouse_pressed(sf::Vector2f mouse_coords)
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

Key * Scale::get_root_key()
{
    return this->root_key;
}

vector<Key *> Scale::get_vector_of_notes()
{
    return this->notes;
}