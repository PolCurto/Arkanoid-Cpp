#include "Destroyer.h"

Destroyer::Destroyer(const sf::Vector2f position) : Item(position, EntityType::Destroyer)
{

}

Destroyer::~Destroyer()
{

}

bool Destroyer::Start()
{
	bool state = Item::Start();

	shape.setPointCount(5);
	shape.setFillColor(sf::Color::Magenta);
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	return state;
}

void Destroyer::Move(const float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);
}