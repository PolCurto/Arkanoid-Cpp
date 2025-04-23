#pragma once

#include "Entity.h"

#include <SFML/Graphics/CircleShape.hpp>

class Ball : public Entity
{
public:
	Ball();
	Ball(const sf::Vector2f& pos);
	~Ball();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState Draw() override;
	bool Close() override;

private:
	sf::CircleShape shape;
};