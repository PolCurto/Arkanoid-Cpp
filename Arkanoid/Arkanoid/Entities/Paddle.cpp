#include "Paddle.h"

#include "Application.h"
#include "RenderModule.h"
#include "InputModule.h"
#include "AudioModule.h"
#include "GameModule.h"
#include "ResourcesModule.h"
#include "Entities/Bullet.h"

bool Paddle::Start()
{
	velocity = defaultVelocity;
	size.x = 200.0f;
	size.y = 20.0f;
	shape.setSize(size);

	position.x = (Globals::ARENA_WIDTH - size.x + Globals::ARENA_H_BORDER * 2) / 2.0f;
	position.y = 850.0f;
	shape.setPosition(position);

	shape.setFillColor(defaultColor);
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor({ 15, 15, 15 });

	leftGun.setTexture(App->resources->GetTexture("gun"));
	rightGun.setTexture(App->resources->GetTexture("gun"));
	leftGun.setSize({ 30.0f, 60.0f });
	rightGun.setSize({ 30.0f, 60.0f });
	SetGunsPositions();

	// Create bullets pool
	const int bulletsSize = 20;
	for (int i = 0; i < bulletsSize; ++i)
	{
		Bullet* newBullet = new Bullet();
		bullets.push_back(newBullet);
		App->game->AddEntity(newBullet);
		newBullet->SetEnabled(false);
	}

	return true;
}

Globals::UpdateState Paddle::Update(float deltaTime)
{
	if (!isEnabled) return Globals::UpdateState::Continue;

	CheckTimers(deltaTime);
	GetInputs(deltaTime);
	Move(deltaTime);
	return Globals::UpdateState::Continue;
}

Globals::UpdateState Paddle::Draw()
{
	if (!isEnabled) return Globals::UpdateState::Continue;

	if (hasGuns)
	{
		App->renderer->Draw(leftGun, Layer::Front);
		App->renderer->Draw(rightGun, Layer::Front);
	}
	App->renderer->Draw(shape, Layer::Front);
	return Globals::UpdateState::Continue;
}

void Paddle::SpeedUp()
{
	isFast = true;
	speedTimer = speederDuration;
	velocity = 1000;
	shape.setFillColor(sf::Color(25, 255, 75));
}

void Paddle::AddGun()
{
	hasGuns = true;
	gunsTimer = gunsDuration;
}

void Paddle::GetInputs(float deltaTime)
{
	currentVelocity = 0;

	if (App->input->IsKeyDown(sf::Keyboard::Scan::Left))
	{
		currentVelocity -= velocity;
	}

	if (App->input->IsKeyDown(sf::Keyboard::Scan::Right))
	{
		currentVelocity += velocity;
	}

	if (hasGuns && App->input->IsKeyDown(sf::Keyboard::Scan::Space))
	{
		Shoot(deltaTime);
	}
}

void Paddle::Move(float deltaTime)
{
	float finalPos = position.x + currentVelocity * deltaTime;

	// Avoid going out of bounds
	if (finalPos > Globals::ARENA_H_BORDER && finalPos + size.x < Globals::ARENA_WIDTH + Globals::ARENA_H_BORDER)
	{
		position.x = finalPos;
		SetGunsPositions();
		shape.setPosition(position);
	}
}

void Paddle::CheckTimers(float deltaTime)
{
	if (isFast)
	{
		speedTimer -= deltaTime;
		if (speedTimer <= 0)
		{
			isFast = false;
			shape.setFillColor(defaultColor);
			speedTimer = 0;
		}
	}

	if (hasGuns)
	{
		gunsTimer -= deltaTime;
		if (gunsTimer <= 0)
		{
			hasGuns = false;
			gunsTimer = 0;
		}
	}

	if (fireTimer < fireRate) fireTimer += deltaTime;
}

void Paddle::SetGunsPositions()
{
	leftGun.setPosition({ position.x, position.y - 60 });
	rightGun.setPosition({ position.x + size.x - 30, position.y - 60 });
}

void Paddle::Shoot(float deltaTime)
{
	if (fireTimer < fireRate) return;

	fireTimer = 0;
	App->audio->PlaySFX("shot");

	// Reuse the same bullets in the pool to avoid creating and destroying them
	if (bulletIndex >= bullets.size()) bulletIndex = 0;

	bullets[bulletIndex]->OnShot({ position.x + 12, position.y - 65 });
	bullets[bulletIndex + 1]->OnShot({ position.x + size.x - 12, position.y - 65 });
	bulletIndex += 2;
}