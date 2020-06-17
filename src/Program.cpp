#include"Program.hpp"

Program::Program(sf::Font & montserrat_regular):
main_window(sf::VideoMode(1760,500),"Creative Process Automator Demp",sf::Style::Close),
background(0,32,43),
montserrat_regular(montserrat_regular),
keyboard(),
activated_key(keyboard.activate_init_white_key(23)),
hovered_key(nullptr),
ctrl_panel(montserrat_regular,activated_key,&keyboard)
{
    this->main_window.setFramerateLimit(30);
    this->keyboard.move_position(0,this->main_window.getSize().y - WhiteKey::Height);

    this->hovering_over_key = false;
}

void Program::check_hovering()
{
    this->mouse_coords = main_window.mapPixelToCoords(sf::Mouse::getPosition(main_window));
    ctrl_panel.hovers_detection(mouse_coords);
    this->new_hovered = keyboard.mouse_over(mouse_coords);
    if(new_hovered!=hovered_key)
    {
        if(hovered_key!=nullptr)hovered_key->reset_color();
        if(new_hovered!=nullptr)
        {
            new_hovered->highlight();
            hovering_over_key=true;
        }
        else hovering_over_key=false;
        hovered_key=new_hovered;
    }
}

void Program::check_events()
{
    while (main_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            main_window.close();
        }
        
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                if(hovering_over_key)
                {
                    if(activated_key!=nullptr) activated_key->deactivate();
                    hovered_key->activate();
                    ctrl_panel.set_root(hovered_key);
                    activated_key=hovered_key;
                }
                else
                {
                    ctrl_panel.mouse_pressed(mouse_coords);
                }
            }
        }

        else if(event.type == sf::Event::MouseButtonReleased)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                ctrl_panel.mouse_released();
            }
        }
        
    }
}

void Program::draw()
{
    this->main_window.clear(this->background);
    this->main_window.draw(this->keyboard);
    this->main_window.draw(this->ctrl_panel);
    this->main_window.display();
}

void Program::run()
{
    while(this->main_window.isOpen())
    {
        this->check_hovering();
        this->check_events();
        this->draw();
    }
}