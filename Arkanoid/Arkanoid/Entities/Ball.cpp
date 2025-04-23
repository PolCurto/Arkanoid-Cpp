#include "Ball.h"

#include "Application.h"
#include "RenderModule.h"

#include <iostream>


Ball::Ball() : Entity(EntityType::Ball)
{

}

Ball::Ball(const sf::Vector2f& pos) : Entity(EntityType::Ball, pos)
{

}

Ball::~Ball()
{

}

bool Ball::Start()
{
	shape.setRadius(15.0f);
	size = shape.getLocalBounds().size;

	position.x = SCREEN_WIDTH / 2;
	position.y = 400.0f;
	shape.setPosition(position);

	shape.setFillColor(sf::Color::Green);
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

void Ball::Move(const float deltaTime)
{
	sf::Vector2f finalPos = position + velocity * direction * deltaTime;

	// Bounce off walls
	if (finalPos.x < 0 || finalPos.x + size.x > SCREEN_WIDTH) direction.x *= -1;
	if (finalPos.y < 0 || finalPos.y + size.y > SCREEN_HEIGHT) direction.y *= -1;

	position = finalPos;
	shape.setPosition(position);

}