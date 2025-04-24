#include "Enlarger.h"

Enlarger::Enlarger(const sf::Vector2f position) : Item(position, EntityType::Enlarger)
{

}

Enlarger::~Enlarger()
{

}

bool Enlarger::Start()
{
	bool state = Item::Start();

	shape.setPointCount(3);
	shape.setFillColor(sf::Color::Yellow);
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	return state;
}

void Enlarger::Move(const float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);
}