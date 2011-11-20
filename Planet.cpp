#include "Planet.hpp"

Planet::Planet(float x, float y, float size, sf::Color color) {
	this.shape = new sf::Shape::Circle(x, y, size, color);
	this.acceleration = new SuperVector2f::Vector2(0,0,0);
	this.velocity = new SuperVector2f::Vector2(0,0,0);
	this.size = size;
}

~Planet::Planet() {
	delete shape;
	delete acceleration;
	delete velocity;
}

void Planet::ApplyForce(SuperVector2f direc, float mag) {
	this.acceleration += (direc*mag);

}

void Planet::MoveMe(float dt) {
	this.velocity += this.acceleration*dt;
	float OffsetX = this.velocity.x * dt;
	float OffsetY = this.velocity.y * dt;
	this.shape.Move(OffsetX, OffsetY);
}
