
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    // Create main window
    sf::RenderWindow App(sf::VideoMode(800, 600), "SFML Shapes");

    // Start game loop
    while (App.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (App.GetEvent(Event))
        {
            // Close window : exit
            if (Event.Type == sf::Event::Closed)
                App.Close();
        }

        // Clear screen
        App.Clear();

        // Draw predefined shapes
        App.Draw(sf::Shape::Line(10, 10, 710, 100, 15, sf::Color::Red));
        App.Draw(sf::Shape::Circle(200, 200, 100, sf::Color::Yellow));
        App.Draw(sf::Shape::Rectangle(350, 200, 600, 350, sf::Color::Green));

        // Build a custom convex shape
        sf::Shape Polygon;
        Polygon.AddPoint(0, -50,  sf::Color(255, 0, 0),     sf::Color(0, 128, 128));
        Polygon.AddPoint(50, 0,   sf::Color(255, 85, 85),   sf::Color(0, 128, 128));
        Polygon.AddPoint(50, 50,  sf::Color(255, 170, 170), sf::Color(0, 128, 128));
        Polygon.AddPoint(0, 100,  sf::Color(255, 255, 255), sf::Color(0, 128, 128));
        Polygon.AddPoint(-50, 50, sf::Color(255, 170, 170), sf::Color(0, 128, 128));
        Polygon.AddPoint(-50, 0,  sf::Color(255, 85, 85),   sf::Color(0, 128, 128));

        // Define an outline width
        Polygon.SetOutlineWidth(10);

        // Disable filling and enable the outline
        Polygon.EnableFill(false);
        Polygon.EnableOutline(true);

        // We can still use the functions common to all SFML drawable objects
        Polygon.SetColor(sf::Color(255, 255, 255, 200));
        Polygon.Move(300, 300);
        Polygon.Scale(3, 2);
        Polygon.Rotate(45);

        // Draw it
        App.Draw(Polygon);

        // Finally, display the rendered frame on screen
        App.Display();
    }

    return EXIT_SUCCESS;
}
