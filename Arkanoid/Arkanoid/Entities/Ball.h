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
	void CheckCollisions();
	void Bounce(const Entity* otherEnt);

private:
	sf::CircleShape shape;

	sf::Vector2f direction = {0.0f, 1.0f};
	float startVelocity = 400;
	float maxVelocity = 700;

	float currentVelocity;
	int hitDamage = 1;
};