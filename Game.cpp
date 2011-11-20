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
	
	// Clock to keep track of time between game loop iterations
	// Used to keep the game running smoothly
	sf::Clock Clock;

	// Color of the main planet
	sf::Color mainColor(100, 100, 100);

	// List of planets 
	vector<Planet::Planet> Planets;

	// The center of the window
	int WindowMidX = App.GetWidth()/2;
	int WindowMidY = App.GetHeight()/2;

	// Add the main planet (being controlled by the gamer) to the center
	// of the window and then add it to the list of planets.
	Planet::Planet mainPlanet(WindowMidX, WindowMidY, STARTING_PLANET_SIZE, mainColor);
	Planets.push_back(mainPlanet);

	// Start game loop
	while (App.IsOpened()) {

		// Get the time elapsed since the last 
		float Time = Clock.GetElapsedTime();
		Clock.Reset();

		// Process events
		sf::Event Event;
		while (App.GetEvent(Event)) {

			// Close window : exit
			if (Event.Type == sf::Event::Closed) {
				App.Close();
			}

			// Clear screen
			App.Clear();
			
			// Track mouse clicks
			if(Event.Type == sf::Event::MouseButtonReleased) {
				cout << "X = " << Event.MouseButton.X << " Y = " << Event.MouseButton.Y << endl;
			}
		}

		// Redraw all the circles
		for (int i = Planets.begin(); i != Planet.end(); i++) {

			// Current planet
			Planet CurrentPlanet = Planets[i];

			// Draw the planet
			App.Draw(CurrentPlanet.GetShape());
		}

		// Finally, display the rendered frame on screen
		App.Display();
	}

	return EXIT_SUCCESS;
}
