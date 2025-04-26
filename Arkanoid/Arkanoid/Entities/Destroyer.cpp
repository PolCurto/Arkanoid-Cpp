#include "Destroyer.h"

#include "Application.h"
#include "ResourcesModule.h"
#include "GameModule.h"
#include "Ball.h"

Destroyer::Destroyer(const sf::Vector2f position) : Item(position)
{

}

Destroyer::~Destroyer()
{

}

bool Destroyer::Start()
{
	bool state = Item::Start();

	shape.setTexture(&App->resources->GetTexture("destroyerItem"));
	velocity = 0;

	return state;
}

void Destroyer::Move(float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);

	velocity += deltaTime * speedIncrease;

	if (CheckCollisions()) App->game->GetBall()->Upgrade();
}