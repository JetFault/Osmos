#include "SuperVector2f.hpp"

SuperVector2f::SuperVector2f(float x, float y)
	: sf::Vector2f(x, y) {
}

SuperVector2f::SuperVector2f(sf::Vector2f vec)
	: sf::Vector2f(vec.x, vec.y) {
}

float SuperVector2f::Length() {
	return sqrt(x*x + y*y);
}

SuperVector2f SuperVector2f::Normalize() {
	this->x /= this->Length();
	this->y /= this->Length();
	return *this;
}

std::ostream& operator<< (std::ostream& str, const SuperVector2f& v)  {
	return str << "(" << v.x << ", " << v.y <<  ")";
}
