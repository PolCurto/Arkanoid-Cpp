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

	position.x = ARENA_WIDTH / 2.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	shape.setFillColor(defaultColor);
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor(defaultOutlineColor);
	return true;
}

UpdateState Ball::Update(float deltaTime)
{
	if (!isEnabled) return UPDATE_CONTINUE;

	CheckEffects(deltaTime);
	Move(deltaTime);
	CheckCollisions();

	// Increase ball speed over time
	currentVelocity += deltaTime * 10; 
	return UPDATE_CONTINUE;
}

UpdateState Ball::Draw()
{
	if (isEnabled) App->renderer->DrawShape(shape);
	return UPDATE_CONTINUE;
}

bool Ball::Close()
{
	return true;
}

void Ball::Reset()
{
	currentVelocity = startVelocity;
	position.x = ARENA_WIDTH / 2.0f;
	position.y = 500.0f;
	shape.setPosition(position);

	direction = { 0.0f, 1.0f };
}

void Ball::Upgrade()
{
	isDestroyer = true;
	timer = destroyerDuration;
	shape.setFillColor({ 89, 255, 131 });
	shape.setOutlineColor({ 255, 124, 122 });
}

void Ball::Move(float deltaTime)
{
	sf::Vector2f finalPos = position + currentVelocity * direction * deltaTime;

	// Gets off stage below, reset ball
	if (finalPos.y + size.y > SCREEN_HEIGHT)
	{
		App->game->OnMiss();
		return;
	}

	// Bounce off walls
	if (finalPos.x < 0 || finalPos.x + size.x > ARENA_WIDTH) direction.x *= -1;
	if (finalPos.y < SCREEN_HEIGHT - ARENA_HEIGHT) direction.y *= -1;

	position = finalPos;
	shape.setPosition(position);
}

void Ball::CheckCollisions()
{
	for (Entity* entity : App->game->GetAllEntities())
	{
		if (!entity->IsEnabled()) continue;

		EntityType entityType = entity->GetType();
		if (entityType == EntityType::Block)
		{
			Block* block = static_cast<Block*>(entity);
			if (shape.getGlobalBounds().findIntersection(block->GetBoundingBox()))
			{
				if (!isDestroyer) Bounce(block);
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

void Ball::CheckEffects(float deltaTime)
{
	if (!isDestroyer) return;

	timer -= deltaTime;
	if (timer <= 0)
	{
		RemoveEffect();
		timer = 0;
	}
}

void Ball::RemoveEffect()
{
	isDestroyer = false;
	shape.setFillColor(defaultColor);
	shape.setOutlineColor(defaultOutlineColor);
}

