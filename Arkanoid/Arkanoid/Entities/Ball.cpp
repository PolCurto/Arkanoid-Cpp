#include "Ball.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Block.h"
#include "Paddle.h"

#include <iostream>

Ball::Ball() : Entity(EntityType::Ball)
{
	currentVelocity = startVelocity;
}

Ball::~Ball()
{

}

bool Ball::Start()
{
	shape.setRadius(10.0f);
	size = shape.getLocalBounds().size;

	position.x = SCREEN_WIDTH / 2.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	shape.setFillColor(sf::Color({ 0, 179, 255 }));
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor({ sf::Color({255, 255, 255}) });
	return true;
}

UpdateState Ball::Update(const float deltaTime)
{
	Move(deltaTime);
	CheckCollisions();
	// Increase ball speed over time
	currentVelocity += deltaTime * 10; 

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
	currentVelocity = startVelocity;
	position.x = SCREEN_WIDTH / 2.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	direction = { 0.0f, -1.0f };
}

void Ball::Move(const float deltaTime)
{
	sf::Vector2f finalPos = position + currentVelocity * direction * deltaTime;

	// Gets off stage below, reset ball
	if (finalPos.y + size.y > SCREEN_HEIGHT)
	{
		App->game->OnMiss();
		return;
	}

	// Bounce off walls
	if (finalPos.x < 0 || finalPos.x + size.x > SCREEN_WIDTH) direction.x *= -1;
	if (finalPos.y < 0) direction.y *= -1;

	position = finalPos;
	shape.setPosition(position);
}

void Ball::CheckCollisions()
{
	for (Entity* entity : App->game->GetAllEntities())
	{
		EntityType entityType = entity->GetType();
		if (entityType == EntityType::Block)
		{
			Block* block = static_cast<Block*>(entity);
			if (shape.getGlobalBounds().findIntersection(block->GetBoundingBox()))
			{
				Bounce(block);
				block->OnHit(hitDamage);
			}
		}
		else if (entityType == EntityType::Paddle)
		{
			if (shape.getGlobalBounds().findIntersection(static_cast<Paddle*>(entity)->GetBoundingBox()))
			{
				Bounce(entity);
			}
		}
	}
}

void Ball::Bounce(const Entity* otherEnt)
{
	const sf::Vector2f ballCenter = position + (size / 2.0f);
	const sf::Vector2f otherCenter = otherEnt->GetPosition() + (otherEnt->GetSize() / 2.0f);
	direction = (ballCenter - otherCenter).normalized();
}

