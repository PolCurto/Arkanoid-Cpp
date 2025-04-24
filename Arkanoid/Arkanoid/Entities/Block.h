#pragma once

#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Block : public Entity
{
public:
	Block();
	Block(const sf::Vector2f position, const sf::Color color, const int score);
	Block(const EntityType type);
	~Block();

	virtual bool Start() override;
	virtual UpdateState Update(float deltaTime) override;
	virtual UpdateState Draw() override;
	virtual bool Close() override;

	void OnHit(const int damage);

	const sf::FloatRect GetBoundingBox() { return shape.getGlobalBounds(); };

private:
	void Destroy();

protected:
	sf::RectangleShape shape;

	sf::Color color;
	unsigned int life = 1;
	float itemRate = 0.8f;

	int score;
};