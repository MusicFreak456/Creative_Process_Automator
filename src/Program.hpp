#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>

#include"Keyboard.hpp"
#include"ControlPanel.hpp"

class Program
{
public:
    sf::RenderWindow main_window;
private:
    sf::Font montserrat_regular;
    sf::Color background;

    Keyboard keyboard;
    Key * hovered_key;
    Key * activated_key;
    Key * new_hovered;

    ControlPanel ctrl_panel;

    bool hovering_over_key;

    sf::Vector2f mouse_coords;
    sf::Event event;

    void check_hovering();
    void check_events();
    void draw();
public:
    Program(sf::Font &);
    void run();
};

#endif