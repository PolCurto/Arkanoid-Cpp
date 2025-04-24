#pragma once

#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

class Item : public Entity
{
public:
	Item(const sf::Vector2f position, const EntityType type);
	~Item();

	virtual bool Start() override;
	virtual UpdateState Update(const float deltaTime) override;
	virtual UpdateState Draw() override;
	virtual bool Close() override;

protected:
	virtual void Move(const float deltaTime) {};

protected:
	sf::CircleShape shape;

	float velocity = 300.0f;
	sf::Vector2f direction = { 0.0f, 1.0f };
};