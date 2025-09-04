#include <SFML/Graphics.hpp>
#include "Vehicle.hpp"
#include <iostream>

int main()
{
    // create window (renderWindow -> has clear method)
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");

    Vehicle car(static_cast<float>(window.getSize().x), 
        static_cast<float>(window.getSize().y));


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();

            // when window is resized
            else if (event->is<sf::Event::Resized>())
            {
                // option two: View is centering objects present in the window
                sf::View view({ 400.f,300.f }, sf::Vector2f(window.getSize()));
                window.setView(view);
            }                                                                        
        }

        car.Steering();
       
        // double buffering
        window.clear(sf::Color::Black); 
        //draw car - rectangle shape for now
        car.draw(window);
        window.display();
    }
}