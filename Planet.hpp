#ifndef PLANET_HPP_
#define PLANET_HPP_

#include <SFML/Graphics/Shape.hpp>
#include "SuperVector2f.hpp"

#define PLANET_MAX_ACCELERATION 10

class Planet {
	sf::Shape shape;
	SuperVector2f acceleration; 
	SuperVector2f velocity;
	float size;

	public:
		Planet(float x, float y, float size, sf::Color color);
		
		sf::Shape& GetShape() { return shape; }

		void SetAccel(SuperVector2f acc) { acceleration = acc; }
		SuperVector2f GetAccel() { return acceleration; }

		void SetVeloc(SuperVector2f vel) { velocity = vel; }
		SuperVector2f GetVeloc() { return velocity; }

		void ResetAccel() { acceleration.x = 0; acceleration.y = 0; }
		
		/**
		 * Apply a force onto the planet.
		 * Calculate the new acceleration.
		 * @param direc: direction that force is coming from
		 * @param mag: magnitude of the force
		 */
		void ApplyForce(SuperVector2f direc, float mag);

		/**
		 * Calculate the new position and velocity of the Planet
		 * after elapsing a time of dt
		 * @param dt: time chunk passed
		 */
		void MoveMe(float dt);

		~Planet();
};

#endif
