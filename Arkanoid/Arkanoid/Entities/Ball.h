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
	void Upgrade();

private:
	void Move(const float deltaTime);
	void CheckCollisions();
	void Bounce(const Entity* otherEnt);
	void CheckEffects(const float deltaTime);
	void RemoveEffect();

private:
	sf::CircleShape shape;

	sf::Vector2f direction = {0.0f, 1.0f};
	float startVelocity = 400;
	float maxVelocity = 700;
	float currentVelocity;

	int hitDamage = 1;

	bool isDestroyer = false;
	float timer = 0;
	float destroyerDuration = 5.0f;

	sf::Color defaultColor = sf::Color({ 0, 179, 255 });
	sf::Color defaultOutlineColor = sf::Color::White;
};