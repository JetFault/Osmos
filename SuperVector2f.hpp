#ifndef SUPER_VECTOR2_HPP
#define SUPER_VECTOR2_HPP

#include <SFML/System/Vector2.hpp>
#include <math.h>
#include <iostream>

class SuperVector2f: public sf::Vector2f {

	friend std::ostream& operator<< (std::ostream& str, const SuperVector2f& v);
	public:
		SuperVector2f();
		SuperVector2f(float x, float y);
		SuperVector2f(sf::Vector2f vec);
	
		SuperVector2f Normalize();
		float Length();
};

#endif
