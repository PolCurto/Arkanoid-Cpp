#include "Enlarger.h"

#include "Application.h"
#include "ResourcesModule.h"
#include "GameModule.h"
#include "AudioModule.h"
#include "Paddle.h"

Enlarger::Enlarger(const sf::Vector2f position) : Item(position)
{

}

Enlarger::~Enlarger()
{

}

bool Enlarger::Start()
{
	bool state = Item::Start();

	shape.setTexture(&App->resources->GetTexture("b"));
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color({ 15, 15, 15 }));

	return state;
}

void Enlarger::Move(float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);

	if (CheckCollisions())
	{
		App->audio->PlaySFX("grow");
		App->game->GetPaddle()->Grow();
	}
}