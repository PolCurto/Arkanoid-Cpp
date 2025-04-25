#include "Paddle.h"

#include "Application.h"
#include "RenderModule.h"
#include "InputModule.h"
#include "ResourcesModule.h"

Paddle::Paddle() : Block(EntityType::Paddle)
{

}

Paddle::~Paddle()
{

}

bool Paddle::Start()
{
	size.x = defaultWidth;
	size.y = 20.0f;
	shape.setSize(size);

	position.x = (ARENA_WIDTH - size.x + ARENA_H_BORDER * 2) / 2.0f;
	position.y = 850.0f;
	shape.setPosition(position);

	shape.setFillColor(defaultColor);
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor({ 15, 15, 15 });

	leftGun.setTexture(&App->resources->GetTexture("gun"));
	rightGun.setTexture(&App->resources->GetTexture("gun"));
	leftGun.setSize({ 30, 60 });
	rightGun.setSize({ 30, 60 });
	SetGunsPositions();

	// Create bullets pool

	return true;
}

UpdateState Paddle::Update(float deltaTime)
{
	if (!isEnabled) return UPDATE_CONTINUE;

	CheckEffects(deltaTime);
	GetInputs(deltaTime);
	Move(deltaTime);
	return UPDATE_CONTINUE;
}

UpdateState Paddle::Draw()
{
	if (!isEnabled) return UPDATE_CONTINUE;

	if (hasGuns)
	{
		App->renderer->DrawShape(leftGun);
		App->renderer->DrawShape(rightGun);
	}
	App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Paddle::Close()
{
	return true;
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
	if (finalPos > ARENA_H_BORDER && finalPos + size.x < ARENA_WIDTH + ARENA_H_BORDER)
	{
		position.x = finalPos;
		SetGunsPositions();
		shape.setPosition(position);
	}
}

void Paddle::CheckEffects(float deltaTime)
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
	
}

void Paddle::SetGunsPositions()
{
	leftGun.setPosition({ position.x, position.y - 60 });
	rightGun.setPosition({ position.x + size.x - 30, position.y - 60 });
}

void Paddle::Shoot(float deltaTime)
{
	if (fireTimer < fireRate) return;

	fireTimer += deltaTime;
}