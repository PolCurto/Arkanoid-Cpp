#include "Bullet.h"

#include "Application.h"
#include "RenderModule.h"
#include "AudioModule.h"
#include "GameModule.h"
#include "Entities/Block.h"

Bullet::Bullet() : Entity(EntityType::Bullet, position)
{

}

Bullet::~Bullet()
{

}

bool Bullet::Start()
{
	shape.setSize({ 5.0f, 15.0f });
	shape.setFillColor({ 255, 122, 33 });
	shape.setOutlineThickness(-1.0f);
	shape.setOutlineColor(sf::Color::Black);
	return true;
}

UpdateState Bullet::Update(float deltaTime)
{
	if (!isEnabled) return UPDATE_CONTINUE;

	Move(deltaTime);
	CheckCollisions();
	return UPDATE_CONTINUE;
}

UpdateState Bullet::Draw()
{
	if (isEnabled) App->renderer->Draw(shape, Layer::Front);
	return UPDATE_CONTINUE;
}

bool Bullet::Close()
{
	return true;
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
	if (position.y + size.y > ARENA_HEIGHT)
	{
		isEnabled = false;
	}

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