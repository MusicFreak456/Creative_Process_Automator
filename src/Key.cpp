#include"Key.hpp"

Key::Key()
{
    this->active = false;
    this->root = false;
    this->scale = false;
    this->chord = false;
    this->playing = false;
}

WhiteKey::WhiteKey():
Key()
{
    
    this->default_color = sf::Color::White;
    this->setFillColor(this->default_color);
    this->setSize(sf::Vector2f(Width,Height));
}

BlackKey::BlackKey():
Key()
{
    this->default_color = sf::Color::Black;
    this->setFillColor(this->default_color);
    this->setSize(sf::Vector2f(Width,Height));
}

bool Key::is_playing()
{
    return this->sound.getStatus() == sf::Sound::Playing;
}

void Key::set_root()
{
    this->root=true;
    this->activate();
}
void Key::unset_root()
{
    this->root=false;
    this->deactivate_playing();
    this->deactivate();
}
bool Key::is_root()
{
    return this->root;
}

void Key::play()
{
    this->sound.setBuffer(this->sound_buffer);
    this->sound.play();
}

void Key::change_volume(float value)
{
    this->sound.setVolume(value);
}

void Key::set_note(string note)
{
    this->note = note;
}
string Key::get_note()
{
    return this->note;
}
void Key::set_value(float value)
{
    this->value=value;
    string file = "./sound_samples/" + to_string((int)value - 1) + ".wav";
    if(!this->sound_buffer.loadFromFile(file))cout << file + " failed to load" << endl;
    this->sound.setBuffer(this->sound_buffer);

}
float Key::get_value()
{
    return this->value;
}

void Key::reset_color()
{
    this->setFillColor(this->default_color);
}


void WhiteKey::highlight()
{
    this->setFillColor(sf::Color(255,219,77));
}
void BlackKey::highlight()
{
    this->setFillColor(sf::Color(230,184,0));
}

void WhiteKey::activate()
{
    this->active = true;
    if(!chord) this->default_color = sf::Color(0,77,38);
    this->reset_color();
}

void BlackKey::activate()
{
    this->active = true;
    if(!chord) this->default_color = sf::Color(0,77,38);
    this->reset_color();
}

void WhiteKey::deactivate()
{
    this->active =false;
    if(playing)
    {
        this->in_play();
        return;
    }
    if(chord){
        this->in_chord();
        return;
    }
    if(scale){
        this->in_scale();
        return;
    }
    if(root){
        this->activate();
        return;
    }
    this->default_color = sf::Color::White;
    this->reset_color();
}

void BlackKey::deactivate()
{
    this->active =false;
    if(playing)
    {
        this->in_play();
        return;
    }
    if(chord){
        this->in_chord();
        return;
    }
    if(scale){
        this->in_scale();
        return;
    }
    if(root){
        this->activate();
        return;
    }
    this->default_color = sf::Color::Black;
    this->reset_color();
}

void Key::deactivate_chord()
{
    this->chord=false;
    this->deactivate();
};
void Key::deactivate_scale()
{
    this->scale=false;
    this->deactivate();
}
void Key::deactivate_playing()
{
    this->playing=false;
    this->deactivate();
}

void WhiteKey::in_scale()
{
    this->active =false;
    this->scale = true;
    if(!chord)this->default_color = sf::Color(102,255,179);
    this->reset_color();
}

void BlackKey::in_scale()
{
    this->active =false;
    this->scale = true;
    if(!chord)this->default_color = sf::Color(0,179,89);
    this->reset_color();
}

void WhiteKey::in_chord()
{
    this->active = false;
    this->chord = true;
    this->default_color = sf::Color(255,51,51);
    this->reset_color();
}

void BlackKey::in_chord()
{
    this->active = false;
    this->chord = true;
    this->default_color = sf::Color(204,0,0);
    this->reset_color();
}

void WhiteKey::in_play()
{
    this->active = false;
    this->playing = true;
    this->default_color = sf::Color(230,153,255);
    this->reset_color();
}

void BlackKey::in_play()
{
    this->active = false;
    this->playing = true;
    this->default_color = sf::Color(57,0,77);
    this->reset_color();
}