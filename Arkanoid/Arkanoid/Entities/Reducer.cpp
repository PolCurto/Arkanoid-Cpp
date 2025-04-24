#include "Reducer.h"

Reducer::Reducer(const sf::Vector2f position) : Item(position, EntityType::Reducer)
{

}

Reducer::~Reducer()
{

}

bool Reducer::Start()
{
	bool state = Item::Start();

	shape.setPointCount(4);
	shape.setFillColor(sf::Color::Red);
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	return state;
}

void Reducer::Move(const float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);
}