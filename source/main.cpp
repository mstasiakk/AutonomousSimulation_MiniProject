#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // create window (renderWindow -> has clear method)
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "My window");


    // create rectangle - sfml learning process
    sf::RectangleShape rectangle({400.f, 200.f});


    // color and outline
    rectangle.setFillColor(sf::Color::Magenta);
    rectangle.setOutlineThickness(2.f);

    // change the default origin
    rectangle.setOrigin({ 200.f,100.f });

    // transformation - for sfml the order of transformations does not matter
    rectangle.setPosition({ 400.f, 300.f });
    rectangle.setRotation(sf::degrees(30.f));
    rectangle.setScale({1.5f, 1.f}); // Scaling through the x and y from the rectangle startpointt - origin point (right upper corner).

    


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
                // option one: View holding objects in the same spots
                //sf::View view(sf::FloatRect({ 0.f, 0.f }, sf::Vector2f(window.getSize())));
                //window.setView(view);

                // option two: View is centering objects present in the window
                sf::View view({ 400.f,300.f }, sf::Vector2f(window.getSize()));
                window.setView(view);
                
                std::cout << "Resized\n";
                std::cout << "Window " << window.getSize().x << ", " << window.getSize().y << "\n";
                std::cout << "View " << window.getView().getSize().x << ", " << window.getView().getSize().y << "\n";
            }                                                                        
        }


        // Rectangle steering
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
            rectangle.move({ -1.f, 0.f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            rectangle.move({ 1.f, 0.f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            rectangle.move({ 0.f, 1.f });
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            rectangle.move({ 0.f, -1.f });


       
        // double buffering
        window.clear(sf::Color::Black); 
        
        //draw rectangle
        window.draw(rectangle);

        window.display();
    }
}