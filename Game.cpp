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
	vector<Planet*> Planets;

	// The center of the window
	int WindowMidX = App.GetWidth()/2;
	int WindowMidY = App.GetHeight()/2;

	// Add the main planet (being controlled by the gamer) to the center
	// of the window and then add it to the list of planets.
	Planet mainPlanet(WindowMidX, WindowMidY, STARTING_PLANET_SIZE, mainColor);
	Planets.push_back(&mainPlanet);

	Planet Planet1(WindowMidX/2, WindowMidY/2, 20, mainColor);
	Planets.push_back(&Planet1);

	Planet Planet2(WindowMidX*1.5, WindowMidY*1.5, 20, mainColor);
	Planets.push_back(&Planet2);
	
/*
	sf::Shape s = mainPlanet.GetShape();

	cout << "Before s Position " << s.GetPosition().x << endl;

	s.SetX(100);

	cout << "After s Position " << s.GetPosition().x << endl;
	cout << "Before s Position " << mainPlanet.GetShape().GetPosition().x << endl;

	mainPlanet.GetShape().SetX(100);

	cout << "After s Position " << mainPlanet.GetShape().GetPosition().x << endl;
*/


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

			// Track mouse clicks
			if(Event.Type == sf::Event::MouseButtonReleased) {
				float MouseX = Event.MouseButton.X - WindowMidX;
				float MouseY = Event.MouseButton.Y - WindowMidY;
				SuperVector2f direction(MouseX, MouseY);
				direction = mainPlanet.GetShape().GetCenter() - direction;
				direction.Normalize();
				cout << " Mouse was clicked at " << Event.MouseButton.X << "," << Event.MouseButton.Y << " I am at " << mainPlanet.GetShape().GetPosition().x << "," << mainPlanet.GetShape().GetPosition().y << " direction = " << direction << std::endl;

				mainPlanet.ApplyForce(direction, 3);

				Planet* poop = new Planet(mainPlanet.GetShape().GetPosition().x + WindowMidX - (direction.x * STARTING_PLANET_SIZE), mainPlanet.GetShape().GetPosition().y + WindowMidY - (direction.y*STARTING_PLANET_SIZE), 10, sf::Color(255,0,0));
				poop->ApplyForce(-direction, 3);
				Planets.push_back(poop);
			}
		}

		App.Clear();

		// Redraw all the circles
		for (vector<Planet*>::iterator it = Planets.begin(); it < Planets.end(); it++) {

			// Current planet
			Planet *CurrentPlanet = *it;

			CurrentPlanet->MoveMe(Time);

			// Draw the planet
			App.Draw(CurrentPlanet->GetShape());

			//cout << "CurrentPlanet's acceleration = " << CurrentPlanet->GetAccel() << " velo = " << CurrentPlanet->GetVeloc() << endl;
		}

		// Finally, display the rendered frame on screen
		App.Display();
	}

	return EXIT_SUCCESS;
}
