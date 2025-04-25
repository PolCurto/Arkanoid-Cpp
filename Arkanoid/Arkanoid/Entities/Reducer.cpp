#include "Reducer.h"

#include "Application.h"
#include "ResourcesModule.h"
#include "AudioModule.h"
#include "GameModule.h"
#include "Paddle.h"

Reducer::Reducer(const sf::Vector2f position) : Item(position)
{

}

Reducer::~Reducer()
{

}

bool Reducer::Start()
{
	bool state = Item::Start();

	velocity = 500.0f;
	shape.setTexture(&App->resources->GetTexture("a"));
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	direction = ((App->game->GetPaddle()->GetPosition() + App->game->GetPaddle()->GetSize() / 2.0f) - position).normalized();

	return state;
}

void Reducer::Move(float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);

	if (CheckCollisions())
	{
		App->audio->PlaySFX("shrink");
		App->game->GetPaddle()->Shrink();
	}
}