#include"Program.hpp"

using namespace std;

int main()
{
    sf::Font montserrat_regular;

    if(montserrat_regular.loadFromFile("fonts/Montserrat-Regular.ttf"))
    {
        cout << "Font regular loaded" << endl;
    }

    Program main_program(montserrat_regular);
    main_program.run();

    return 0;
}