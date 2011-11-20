#include "Planet.hpp"

Planet::Planet(float x, float y, float size, sf::Color color) {
	std::cout << " x = " << x << " y = " << y << std::endl;
	this->shape = sf::Shape::Circle(0, 0, size, color);
	//this->shape.SetPosition(Vector2f(x, y));
	std::cout << "My position is " << this->shape.GetPosition().x << ", " << this->shape.GetPosition().y << std::endl;
	this->size = size;
}

Planet::~Planet() {
}

void Planet::ApplyForce(SuperVector2f direc, float mag) {
	this->acceleration += (direc * mag);

}

void Planet::MoveMe(float dt) {
	this->velocity += this->acceleration*dt;

	float OffsetX = this->velocity.x * dt;
	float OffsetY = this->velocity.y * dt;
	this->shape.Move(OffsetX, OffsetY);
}
