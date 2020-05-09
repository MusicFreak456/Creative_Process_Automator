#include"Chord.hpp"

ChordBracket::ChordBracket(ScaleBracket* scale,Keyboard * keyboard ,sf::Font& font): scale(scale), keyboard(keyboard)
{
    this->title.setFont(font);
    this->title.setCharacterSize(24);
    this->title.setPosition(1104,0);
    this->title.setString("Chords:");

    this->border.setPosition(1104,0);
    this->border.setSize(sf::Vector2f(546,300));
    this->border.setFillColor(sf::Color(255,255,255,5));

    this->generate_chords();
}

void ChordBracket::generate_chords()
{
    Chord * new_chord;

    new_chord = new MajorChord(1130,40);
    this->chords.push_back(new_chord);

    new_chord = new MinorChord(1130,42+40);
    this->chords.push_back(new_chord);

    new_chord = new MinorChord(1130,44+80);
    this->chords.push_back(new_chord);

    new_chord = new MajorChord(1130,46+120);
    this->chords.push_back(new_chord);

    new_chord = new MajorChord(1130,48+160);
    this->chords.push_back(new_chord);

    new_chord = new MinorChord(1130,50+200);
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

Chord::Chord(int posx, int posy)
{
    this->border.setPosition(posx,posy);
    this->border.setSize(sf::Vector2f(500,40));
    this->border.setFillColor(sf::Color(255,255,255,10));
}

MajorChord::MajorChord(int posx,int posy):Chord(posx,posy){}

void MajorChord::generate(Key* start_key)
{}

void Chord::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
    target.draw(this->border,states);
}

MinorChord::MinorChord(int posx,int posy):Chord(posx,posy){}

void MinorChord::generate(Key* start_key)
{}




