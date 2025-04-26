#pragma once

#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

class Ball : public Entity
{
public:
	Ball() : Entity(EntityType::Ball) {};
	~Ball() override = default;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState Draw() override;

	void Reset();
	void Upgrade();

private:
	void Move(float deltaTime);
	void CheckCollisions();
	void Bounce(const Entity* otherEnt);
	void CheckEffects(float deltaTime);
	void RemoveEffect();

private:
	sf::CircleShape shape;

	sf::Vector2f direction = {0.0f, 1.0f};
	float startVelocity = 400;
	float maxVelocity = 700;
	float currentVelocity = 0;

	int hitDamage = 1;

	bool isDestroyer = false;
	float timer = 0;
	float destroyerDuration = 5.0f;

	float paddleCollisionTime = 0.3f;
	float paddleTimer;
	float wallCollisionTime = 0.1f;
	float wallTimer;

	sf::Color defaultColor = sf::Color({ 0, 179, 255 });
	sf::Color defaultOutlineColor = sf::Color::White;
};