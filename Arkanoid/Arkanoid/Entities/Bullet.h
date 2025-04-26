#pragma once

#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Bullet : public Entity
{
public:
	Bullet();
	~Bullet() override;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState Draw() override;
	bool Close() override;

	void OnShot(const sf::Vector2f& newPos);

protected:
	void Move(float deltaTime);
	void CheckCollisions();

protected:
	sf::RectangleShape shape;

	float velocity = 500.0f;
	sf::Vector2f direction = { 0.0f, -1.0f };

	int hitDamage = 1;
};