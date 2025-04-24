#include "Reducer.h"

#include "Application.h"
#include "GameModule.h"
#include "Paddle.h"

Reducer::Reducer(const sf::Vector2f position) : Item(position, EntityType::Reducer)
{

}

Reducer::~Reducer()
{

}

bool Reducer::Start()
{
	bool state = Item::Start();

	velocity = 500.0f;
	shape.setPointCount(4);
	shape.setFillColor(sf::Color::Red);
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	direction = ((App->game->GetPaddle()->GetPosition() + App->game->GetPaddle()->GetSize() / 2.0f) - position).normalized();

	return state;
}

void Reducer::Move(const float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);

	if (CheckCollisions())
	{
		App->game->GetPaddle()->Shrink();
	}
}