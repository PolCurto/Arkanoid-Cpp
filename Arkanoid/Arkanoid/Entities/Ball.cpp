#include "Ball.h"

#include "Application.h"
#include "AudioModule.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "Block.h"
#include "Paddle.h"

bool Ball::Start()
{
	currentVelocity = startVelocity;
	paddleTimer = 0;

	shape.setRadius(10.0f);
	size = shape.getLocalBounds().size;

	position.x = Globals::ARENA_WIDTH / 2.0f - shape.getRadius() + Globals::ARENA_H_BORDER;
	position.y = 800.0f;
	shape.setPosition(position);

	shape.setFillColor(defaultColor);
	shape.setOutlineThickness(2.0f);
	shape.setOutlineColor(defaultOutlineColor);
	return true;
}

Globals::UpdateState Ball::Update(float deltaTime)
{
	if (!isEnabled) return Globals::UpdateState::Continue;

	CheckEffects(deltaTime);
	Move(deltaTime);
	CheckCollisions();

	// Increase ball speed over time
	constexpr float maxVelocity = 800.0f;
	if (currentVelocity < maxVelocity) currentVelocity += deltaTime * 10;

	return Globals::UpdateState::Continue;
}

Globals::UpdateState Ball::Draw() const
{
	if (isEnabled) App->renderer->Draw(shape, Layer::Front);
	return Globals::UpdateState::Continue;
}

void Ball::Reset()
{
	currentVelocity = startVelocity;
	position.x = Globals::ARENA_WIDTH / 2.0f - shape.getRadius() + Globals::ARENA_H_BORDER;
	position.y = 800.0f;
	shape.setPosition(position);

	direction = { 0.0f, -1.0f };
}

void Ball::Upgrade()
{
	App->audio->PlaySFX("destroyer");

	isDestroyer = true;
	timer = destroyerDuration;
	shape.setFillColor({ 89, 255, 131 });
	shape.setOutlineColor({ 255, 124, 122 });
}

void Ball::Move(float deltaTime)
{
	const sf::Vector2f finalPos = position + currentVelocity * direction * deltaTime;

	// Gets off stage below, reset ball
	if (finalPos.y + size.y > Globals::SCREEN_HEIGHT)
	{
		App->game->OnMiss();
		return;
	}

	// Bounce off walls
	if (wallTimer <= 0)
	{
		bool bounce = false;

		if (finalPos.x < Globals::ARENA_H_BORDER || finalPos.x + size.x > Globals::ARENA_WIDTH + Globals::ARENA_H_BORDER)
		{
			bounce = true;
			direction.x *= -1;
		}
		if (finalPos.y < Globals::TOP_PANEL_HEIGHT + Globals::ARENA_V_BORDER)
		{
			bounce = true;
			direction.y *= -1;
		}

		if (bounce) 
		{
			wallTimer = wallCollisionTime;
			App->audio->PlaySFX("wallBounce");
		}
	}

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
		else if (entityType == EntityType::Paddle && paddleTimer <= 0.0f)
		{
			if (shape.getGlobalBounds().findIntersection(static_cast<Paddle*>(entity)->GetBoundingBox()))
			{
				paddleTimer = paddleCollisionTime;
				App->audio->PlaySFX("paddleBounce");
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
	if (paddleTimer > 0.0f) paddleTimer -= deltaTime;
	if (wallTimer > 0.0f) wallTimer -= deltaTime;

	if (!isDestroyer) return;

	timer -= deltaTime;
	if (timer <= 0.0f)
	{
		RemoveEffect();
		timer = 0.0f;
	}
}

void Ball::RemoveEffect()
{
	isDestroyer = false;
	shape.setFillColor(defaultColor);
	shape.setOutlineColor(defaultOutlineColor);
}

