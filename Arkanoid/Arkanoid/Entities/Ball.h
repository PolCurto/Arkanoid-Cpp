#pragma once

#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

class Ball : public Entity
{
public:
	Ball();
	~Ball();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState Draw() override;
	bool Close() override;

	void Reset();

private:
	void Move(const float deltaTime);

private:
	sf::CircleShape shape;

	sf::Vector2f direction = {1.0f, 1.0f};
	float velocity = 500;
};