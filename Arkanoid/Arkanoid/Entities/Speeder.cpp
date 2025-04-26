#include "Speeder.h"

#include "Application.h"
#include "ResourcesModule.h"
#include "GameModule.h"
#include "AudioModule.h"
#include "Paddle.h"

bool Speeder::Start()
{
	bool state = Item::Start();

	shape.setTexture(App->resources->GetTexture("speederItem"));

	return state;
}

void Speeder::Move(float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);

	if (CheckCollisions())
	{
		App->audio->PlaySFX("grow");
		App->game->GetPaddle()->SpeedUp();
	}
}