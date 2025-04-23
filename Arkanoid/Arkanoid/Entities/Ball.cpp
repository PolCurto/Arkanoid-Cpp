#include "Ball.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"

#include <iostream>

Ball::Ball() : Entity(EntityType::Ball)
{

}

Ball::~Ball()
{

}

bool Ball::Start()
{
	shape.setRadius(15.0f);
	size = shape.getLocalBounds().size;

	position.x = SCREEN_WIDTH / 2.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	shape.setFillColor(sf::Color({ 29, 127, 224 }));
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor({ sf::Color({15, 15, 15}) });
	return true;
}

UpdateState Ball::Update(const float deltaTime)
{
	Move(deltaTime);
	return UPDATE_CONTINUE;
}

UpdateState Ball::Draw()
{
	App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Ball::Close()
{
	return true;
}

void Ball::Reset()
{
	position.x = SCREEN_WIDTH / 2.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	direction = { 0.0f, -1.0f };
}

void Ball::Move(const float deltaTime)
{
	sf::Vector2f finalPos = position + velocity * direction * deltaTime;

	// Bounce off walls
	if (finalPos.x < 0 || finalPos.x + size.x > SCREEN_WIDTH) direction.x *= -1;
	if (finalPos.y < 0) direction.y *= -1;

	// TODO: Check collisions with blocks / paddle

	// Gets off stage below, reset ball
	if (finalPos.y + size.y > SCREEN_HEIGHT) App->game->OnMiss();

	position = finalPos;
	shape.setPosition(position);

}

