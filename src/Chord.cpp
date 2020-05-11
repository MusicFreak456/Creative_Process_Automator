#include"Chord.hpp"

ChordBracket::ChordBracket(Keyboard * keyboard ,sf::Font& font): 
keyboard(keyboard),
font(font)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1104,0);
    this->title.setString("Chords:");

    this->border.setPosition(1104,0);
    this->border.setSize(sf::Vector2f(546,300));
    this->border.setFillColor(sf::Color(255,255,255,5));
}

void ChordBracket::set_scale(ScaleBracket* scale)
{
    this->scale = scale;
    this->chords = vector<Chord*>();
    generate_chords(this->font,this->scale);
}

void ChordBracket::generate_chords(sf::Font& font,ScaleBracket * scale)
{
    Chord * new_chord;

    int quantity = scale->notes.size();
    int count = 0;

    new_chord = new MajorChord(font,"I",scale->notes[count],this->keyboard,1130,40);
    this->chords.push_back(new_chord);
    count++;

    new_chord = new MinorChord(font,"ii",scale->notes[count],this->keyboard,1130,42+40);
    this->chords.push_back(new_chord);
    count++;

    new_chord = new MinorChord(font,"iii",scale->notes[count],this->keyboard,1130,44+80);
    this->chords.push_back(new_chord);
    count++;

    new_chord = new MajorChord(font,"IV",scale->notes[count],this->keyboard,1130,46+120);
    this->chords.push_back(new_chord);
    count++;

    new_chord = new MajorChord(font,"V",scale->notes[count],this->keyboard,1130,48+160);
    this->chords.push_back(new_chord);
    count++;

    new_chord = new MinorChord(font,"vi",scale->notes[count],this->keyboard,1130,50+200);
    this->chords.push_back(new_chord);
}

void ChordBracket::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->title,states);
    for(const Chord* x : this->chords)
    {
        target.draw(*x,states);
    }
}

Chord::Chord(sf::Font& font,string name,Key* start_key,Keyboard * keyboard,int posx, int posy): 
start_key(start_key)
{
    this->border.setPosition(posx,posy);
    this->border.setSize(sf::Vector2f(500,40));
    this->border.setFillColor(sf::Color(255,255,255,10));
 
    this->tiles.push_back(ChordBracketTile(font,name,posx+22,posy+2,true));
}

MajorChord::MajorChord(sf::Font& font,string name,Key * start_key,Keyboard* keyboard,int posx,int posy):
Chord(font,name,start_key,keyboard,posx,posy)
{
    this->generate(font,start_key,keyboard,posx+22+ChordBracketTile::width+2,posy+2);
}

void MajorChord::generate(sf::Font& font,Key* start_key,Keyboard* keyboard,int start_posx, int start_posy)
{
    this->keys.push_back(start_key);
    int start_key_value = start_key->get_value();
    this->tiles.push_back(ChordBracketTile(font,start_key->get_note(),start_posx,start_posy,false));

    Key * next = keyboard->find_key(start_key_value+4);
    if(next == nullptr) return;
    this->keys.push_back(next);
    this->tiles.push_back(ChordBracketTile(font,next->get_note(),start_posx + ChordBracketTile::width+2,start_posy,false));

    next = keyboard->find_key(start_key_value+7);
    if(next == nullptr) return;
    this->keys.push_back(next);
    this->tiles.push_back(ChordBracketTile(font,next->get_note(),start_posx + ChordBracketTile::width*2+4,start_posy,false));
}

void Chord::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);

    for(const ChordBracketTile& x : this->tiles)
    {
        target.draw(x,states);
    }
}

MinorChord::MinorChord(sf::Font& font,string name,Key* start_key,Keyboard* keyboard,int posx,int posy):
Chord(font,name,start_key,keyboard,posx,posy)
{
    this->generate(font,start_key,keyboard,posx+22+ChordBracketTile::width+2,posy+2);
}

void MinorChord::generate(sf::Font& font,Key* start_key,Keyboard * keyboard,int start_posx, int start_posy)
{
    this->keys.push_back(start_key);
    int start_key_value = start_key->get_value();
    this->tiles.push_back(ChordBracketTile(font,start_key->get_note(),start_posx,start_posy,false));

    Key * next = keyboard->find_key(start_key_value+3);
    if(next == nullptr) return;
    this->keys.push_back(next);
    this->tiles.push_back(ChordBracketTile(font,next->get_note(),start_posx + ChordBracketTile::width+2,start_posy,false));

    next = keyboard->find_key(start_key_value+7);
    if(next == nullptr) return;
    this->keys.push_back(next);
    this->tiles.push_back(ChordBracketTile(font,next->get_note(),start_posx + ChordBracketTile::width*2+4,start_posy,false));
}

ChordBracketTile::ChordBracketTile(sf::Font& font,string label,int posx, int posy, bool opacity)
{
    this->border.setPosition(posx,posy);
    this->border.setSize(sf::Vector2f(this->width,this->height));
    this->border.setFillColor(sf::Color(255,255,255,opacity? 0 : 5));

    this->text.setFont(font);
    this->text.setString(label);
    this->text.setPosition(posx+10,posy+3);
    this->text.setCharacterSize(24);
}

void ChordBracketTile::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
    target.draw(this->text,states);
}


