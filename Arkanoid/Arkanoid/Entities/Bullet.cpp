#include "Bullet.h"

#include "Application.h"
#include "RenderModule.h"
#include "AudioModule.h"
#include "GameModule.h"
#include "Entities/Block.h"

bool Bullet::Start()
{
	shape.setSize({ 5.0f, 15.0f });
	shape.setFillColor({ 255, 122, 33 });
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color::Black);
	return true;
}

Globals::UpdateState Bullet::Update(float deltaTime)
{
	if (!isEnabled) return Globals::UpdateState::Continue;

	Move(deltaTime);
	CheckCollisions();
	return Globals::UpdateState::Continue;
}

Globals::UpdateState Bullet::Draw() const
{
	if (isEnabled) App->renderer->Draw(shape, Layer::Front);
	return Globals::UpdateState::Continue;
}

void Bullet::OnShot(const sf::Vector2f& newPos)
{
	position = newPos;
	shape.setPosition(position);
	isEnabled = true;
}

void Bullet::Move(float deltaTime)
{
	position += direction * velocity * deltaTime;
	shape.setPosition(position);
}

void Bullet::CheckCollisions()
{
	// If it goes off screen, disable
	if (position.y < Globals::TOP_PANEL_HEIGHT + Globals::ARENA_V_BORDER) isEnabled = false;

	// Check collisions with blocks
	for (Entity* entity : App->game->GetAllEntities())
	{
		if (!entity->IsEnabled()) continue;

		if (entity->GetType() == EntityType::Block)
		{
			Block* block = static_cast<Block*>(entity);
			if (shape.getGlobalBounds().findIntersection(block->GetBoundingBox()))
			{
				block->OnHit(hitDamage);
				isEnabled = false;
			}
		}
	}
}