#include"Chord.hpp"

Chords::Chords(Keyboard * keyboard,Scale* scale): 
keyboard(keyboard),
scale(scale)
{
    this->set_scale(this->scale);
}

ChordsSFMLWindow::ChordsSFMLWindow(Chords& chords,sf::Font& font):
font(font),
chords(chords)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1104,0);
    this->title.setString("Chords:");

    this->border.setPosition(1104,0);
    this->border.setSize(sf::Vector2f(546,300));
    this->border.setFillColor(sf::Color(255,255,255,5));

    vector<Chord*> vector_of_all_chords = this->chords.get_vector_of_all_chords();

    for(Chord * x: vector_of_all_chords)
    {
        this->vector_of_sfml_chords.push_back(new ChordSFML(*x,font,this->vector_of_sfml_chords,x->get_posx(),x->get_posy()));
    }
}

void ChordsSFMLWindow::hovers_detection(sf::Vector2f mousepos)
{
    for(ChordSFML* x: this->vector_of_sfml_chords)
    {
        x->hovers_detection(mousepos);
    }
}

void ChordsSFMLWindow::mouse_pressed(sf::Vector2f mousepos)
{
    for(ChordSFML* x: this->vector_of_sfml_chords)
    {
        x->mouse_pressed(mousepos);
    }
}

void Chords::set_scale(Scale* scale)
{
    this->scale = scale;
    this->chords = vector<Chord*>();
    generate_chords(this->scale);
}

vector<Chord*> Chords::get_vector_of_all_chords()
{
    return this->chords;
}

void ChordsSFMLWindow::set_scale(Scale * scale)
{
    this->chords.set_scale(scale);
    for(ChordSFML* x: this->vector_of_sfml_chords)
    {
        x->change_root();
    }

    vector<Chord*> vector_of_all_chords = this->chords.get_vector_of_all_chords();
    this->vector_of_sfml_chords.clear();
    for(Chord * x: vector_of_all_chords)
    {
        this->vector_of_sfml_chords.push_back(new ChordSFML(*x,font,this->vector_of_sfml_chords,x->get_posx(),x->get_posy()));
    }
}

void Chords::generate_chords(Scale * scale)
{
    Chord * new_chord;

    for(Chord * x : this->chords)
    {
        delete(x);
    }

    this->chords.clear();

    vector<Key *> scale_notes = scale->get_vector_of_notes();
    int quantity = scale_notes.size();
    int count = 0;

    new_chord = new MajorChord("I",scale_notes[count],this->keyboard,1130,40);
    this->chords.push_back(new_chord);
    count++;

    if(count == quantity) return;
    new_chord = new MinorChord("ii",scale_notes[count],this->keyboard,1130,42+40);
    this->chords.push_back(new_chord);
    count++;

    if(count == quantity) return;
    new_chord = new MinorChord("iii",scale_notes[count],this->keyboard,1130,44+80);
    this->chords.push_back(new_chord);
    count++;

    if(count == quantity) return;
    new_chord = new MajorChord("IV",scale_notes[count],this->keyboard,1130,46+120);
    this->chords.push_back(new_chord);
    count++;

    if(count == quantity) return;
    new_chord = new MajorChord("V",scale_notes[count],this->keyboard,1130,48+160);
    this->chords.push_back(new_chord);
    count++;

    if(count == quantity) return;
    new_chord = new MinorChord("vi",scale_notes[count],this->keyboard,1130,50+200);
    this->chords.push_back(new_chord);
}

void ChordsSFMLWindow::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    for(const ChordSFML* x : this->vector_of_sfml_chords)
    {
        target.draw(*x,states);
    }
}

Chord::Chord(string name,Key* start_key,Keyboard * keyboard,int posx, int posy): 
start_key(start_key),
keyboard(keyboard),
name(name),
posx(posx),
posy(posy),
invertable(name == "IV" || name == "V" || name == "vi")
{}

ChordSFML::ChordSFML(Chord& chord, sf::Font& font, vector<ChordSFML*>& all_chords, int posx, int posy):
chord(chord),
all_chords(all_chords),
show_check_box("show",font),
play_box("play",font),
invert_check_box("invert",font),
show_chord(false),
playing(false),
inverted(false)
{
    this->border.setPosition(posx,posy);
    this->border.setSize(sf::Vector2f(517,40));
    this->border.setFillColor(sf::Color(255,255,255,10));

    int box_width = 85;
    int box_height = 30;

    this->show_check_box.change_size(box_width,box_height);
    this->show_check_box.move_position(posx+512-box_width,posy+5);

    this->play_box.change_size(box_width-7,box_height);
    this->play_box.move_position(posx+512-2*box_width+4,posy+5);

    this->invert_check_box.change_size(box_width+7,box_height);
    this->invert_check_box.move_position(posx+512-3*box_width-6,posy+5);

    this->tiles.push_back(NoteSFMLTile(font,this->chord.get_name(),posx+22,posy+2,true));

    vector<Key *> vector_of_keys =this->chord.get_vector_of_keys();

    int i = 0;

    int start_posx = posx+22+NoteSFMLTile::width+2;
    int start_posy = posy+2;

    for(Key * x : vector_of_keys)
    {
        this->tiles.push_back(NoteSFMLTile(font,x->get_note(),start_posx + (NoteSFMLTile::width * i)+(i * 2),start_posy,false));
        i++;
    }
}

vector<Key*> Chord::get_vector_of_keys()
{
    return this->keys;
}

int Chord::get_posx()
{
    return this->posx;
}

int Chord::get_posy()
{
    return this->posy;
}

string Chord::get_name()
{
    return this->name;
}

void ChordSFML::change_root()
{
    this->dark_down();
    this->show_check_box.uncheck();
}

void ChordSFML::light_up()
{
    vector<Key *> vector_of_keys =this->chord.get_vector_of_keys();

    this->show_chord = true;
    for(Key * k : vector_of_keys)
    {
        k->in_chord();
    }
}
void ChordSFML::dark_down()
{
    vector<Key *> vector_of_keys =this->chord.get_vector_of_keys();

    this->show_chord = false;
    for(Key * k : vector_of_keys)
    {
        k->deactivate_chord();
    }
}

bool ChordSFML::is_shown()
{
    return  this->show_chord;
}

MajorChord::MajorChord(string name,Key * start_key,Keyboard* keyboard,int posx,int posy):
Chord(name,start_key,keyboard,posx,posy)
{
    this->generate(start_key);
}

void MajorChord::generate(Key* start_key)
{
    this->keys.push_back(start_key);
    int start_key_value = start_key->get_value();

    Key * next = this->keyboard->find_key(start_key_value+4);
    if(next == nullptr) return;
    this->keys.push_back(next);

    next = this->keyboard->find_key(start_key_value+7);
    if(next == nullptr) return;
    this->keys.push_back(next);
}

void ChordSFML::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->show_check_box,states);
    if(this->chord.invertable)target.draw(this->invert_check_box,states);
    target.draw(this->play_box,states);

    for(const NoteSFMLTile& x : this->tiles)
    {
        target.draw(x,states);
    }
}

void Chord::play()
{
    for(Key * x : this->keys)
    {
        x->play();
    }
}

void Chord::invert(int by_value)
{
    int number_of_keys = this->keys.size();
    if(number_of_keys <= 1) return;

    Key * key;
    int value;

    if(name == "vi")
    {
        key = this->keys[1];
        value = key->get_value();
        value += by_value;
        key = this->keyboard->find_key(value);
        this->keys[1] = key;

        if(number_of_keys > 2)
        {
            key = this->keys[2];
            value = key->get_value();
            value += by_value;
            key = this->keyboard->find_key(value);
            this->keys[2] = key;
        }

    }
    else
    {
        if(number_of_keys > 2)
        {
            key = this->keys[2];
            value = key->get_value();
            value += by_value;
            key = this->keyboard->find_key(value);
            this->keys[2] = key;
        }
    }
}

bool Chord::is_playing()
{
    for(Key * x: this->keys)
    {
        return x->is_playing();
    }
    return false;
}

void ChordSFML::hovers_detection(sf::Vector2f mousepos)
{
    this->show_check_box.hovers_detection(mousepos);
    if(this->chord.invertable)this->invert_check_box.hovers_detection(mousepos);
    this->play_box.hovers_detection(mousepos);

    if(play_box.is_checked())
    {
        if(!this->chord.is_playing())
        {
            this->play_box.uncheck();
            this->playing = false;
        }
    }
}
void ChordSFML::mouse_pressed(sf::Vector2f mousepos)
{
    this->show_check_box.mouse_pressed(mousepos);
    if(this->show_check_box.is_checked() && !this->show_chord)
    {
        for(ChordSFML * x: this->all_chords)
        {
            if(x!=this)x->change_root();
        }
        this->show_chord = true;
        this->light_up();
    }
    else if (!this->show_check_box.is_checked() && this->show_chord)
    {
        this->show_chord = false;
        this->dark_down();
    }

    this->play_box.mouse_pressed(mousepos);
    if(this->play_box.is_checked() & !this->playing) 
    {
        this->chord.play();
        this->playing = true;
    }

    if(this->chord.invertable)
    {
        bool light_up = false;
        this->invert_check_box.mouse_pressed(mousepos);
        if(this->invert_check_box.is_checked() && !this->inverted)
        {
            if(this->show_chord)
            {
                light_up = true;
                this->dark_down();
            }
            this->chord.invert(-12);
            if(light_up)this->light_up();
            this->inverted = true;
        }
        else if (!this->invert_check_box.is_checked() && this->inverted)
        {
            if(this->show_chord)
            {
                light_up = true;
                this->dark_down();
            }
            this->chord.invert(12);
            if(light_up)this->light_up();
            this->inverted = false;
        }
    }
    
}

MinorChord::MinorChord(string name,Key* start_key,Keyboard* keyboard,int posx,int posy):
Chord(name,start_key,keyboard,posx,posy)
{
    this->generate(start_key);
}

void MinorChord::generate(Key* start_key)
{
    this->keys.push_back(start_key);
    int start_key_value = start_key->get_value();

    Key * next = this->keyboard->find_key(start_key_value+3);
    if(next == nullptr) return;
    this->keys.push_back(next);

    next = this->keyboard->find_key(start_key_value+7);
    if(next == nullptr) return;
    this->keys.push_back(next);
}

NoteSFMLTile::NoteSFMLTile(sf::Font& font,string label,int posx, int posy, bool opacity)
{
    this->border.setPosition(posx,posy);
    this->border.setSize(sf::Vector2f(this->width,this->height));
    this->border.setFillColor(sf::Color(255,255,255,opacity? 0 : 5));

    this->text.setFont(font);
    this->text.setString(label);
    this->text.setPosition(posx+10,posy+3);
    this->text.setCharacterSize(24);
}

void NoteSFMLTile::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->text,states);
}