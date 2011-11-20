#include "Game.hpp"


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////

using namespace std;

int main() {
	// Create main window
	sf::RenderWindow App(sf::VideoMode(800, 600), "SFML Shapes");

	// Start game loop
	while (App.IsOpened()) {
		// Process events
		sf::Event Event;
		while (App.GetEvent(Event)) {

			//Close window : exit
			if (Event.Type == sf::Event::Closed) {
				App.Close();
			}
			
			//Mouse button
			if(Event.Type == sf::Event::MouseButtonReleased) {
				cout << "X = " << Event.MouseButton.X << " Y = " << Event.MouseButton.Y << endl;
			}
		}

		// Clear screen
		App.Clear();

		//draw the circle
		App.Draw(sf::Shape::Circle(200, 200, 100, sf::Color::Yellow));

		// Finally, display the rendered frame on screen
		App.Display();
	}

	return EXIT_SUCCESS;
}
