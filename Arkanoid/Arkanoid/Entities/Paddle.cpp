#include "Paddle.h"

#include "Application.h"
#include "RenderModule.h"
#include "InputModule.h"

#include <iostream>

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

	position.x = (ARENA_WIDTH - size.x) / 2.0f;
	position.y = 800.0f;
	shape.setPosition(position);

	shape.setFillColor(defaultColor);
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor({ sf::Color({15, 15, 15}) });
	return true;
}

UpdateState Paddle::Update(float deltaTime)
{
	if (!isEnabled) return UPDATE_CONTINUE;

	CheckEffects(deltaTime);
	GetInputs();
	Move(deltaTime);
	return UPDATE_CONTINUE;
}

UpdateState Paddle::Draw()
{
	if (isEnabled) App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Paddle::Close()
{
	return true;
}

void Paddle::Grow()
{
	if (mode != PaddleMode::Large)
	{
		mode = PaddleMode::Large;
		timer = effectDuration;
		size.x = 300.0f;
		shape.setPosition(position);
		shape.setSize(size);
		shape.setFillColor(sf::Color(175, 175, 175));
	}
}

void Paddle::Shrink()
{
	if (mode != PaddleMode::Small)
	{
		mode = PaddleMode::Small;
		timer = effectDuration;
		size.x = 100.0f;
		shape.setPosition(position);
		shape.setSize(size);
		shape.setFillColor(sf::Color(75, 75, 75));
	}
}

void Paddle::GetInputs()
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
}

void Paddle::Move(float deltaTime)
{
	float finalPos = position.x + currentVelocity * deltaTime;

	// Avoid going out of bounds
	if (finalPos > 0 && finalPos + size.x < ARENA_WIDTH)
	{
		position.x = finalPos;
		shape.setPosition(position);
	}
}

void Paddle::CheckEffects(float deltaTime)
{
	if (mode == PaddleMode::Default) return;

	timer -= deltaTime;
	if (timer <= 0) 
	{
		ResetSize();
		timer = 0;
	}
}

void Paddle::ResetSize()
{
	shape.setFillColor(defaultColor);
	mode = PaddleMode::Default;
	size.x = defaultWidth;
	shape.setSize(size);
}