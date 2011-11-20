#include "Planet.hpp"

Planet::Planet(float x, float y, float size, sf::Color color) {
	this->shape = sf::Shape::Circle(x, y, size, color);
	this->size = size;
}

Planet::~Planet() {
}

void Planet::ApplyForce(SuperVector2f direc, float mag) {
	this->acceleration += (direc * mag);
	if(this->acceleration.Length() > PLANET_MAX_ACCELERATION) {
		this->acceleration.Normalize();
		this->acceleration.x = (this->acceleration.x) * PLANET_MAX_ACCELERATION;
		this->acceleration.y = (this->acceleration.y) * PLANET_MAX_ACCELERATION;
	}

}

void Planet::MoveMe(float dt) {
	this->velocity += this->acceleration*dt;

	float OffsetX = this->velocity.x * dt;
	float OffsetY = this->velocity.y * dt;
	this->shape.Move(OffsetX, OffsetY);
}
