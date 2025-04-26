#pragma once

#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

class Item : public Entity
{
public:
	Item(const sf::Vector2f position) : Entity(EntityType::Item, position) {};
	virtual ~Item() override = default;

	virtual bool Start() override;
	virtual Globals::UpdateState Update(float deltaTime) override;
	virtual Globals::UpdateState Draw() override;

protected:
	virtual void Move(float deltaTime) {};
	bool CheckCollisions();

protected:
	sf::CircleShape shape;

	float velocity = 300.0f;
	sf::Vector2f direction = { 0.0f, 1.0f };
};