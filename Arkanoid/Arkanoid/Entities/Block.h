#pragma once

#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Item;

class Block : public Entity
{
public:
	Block(const sf::Vector2f position, const sf::Color color, const int score);
	Block(const EntityType type) : Entity(type) {}
	virtual ~Block() override = default;

	virtual bool Start() override;
	virtual Globals::UpdateState Draw() const override;

	void OnHit(const int damage);

	const sf::FloatRect GetBoundingBox() const { return shape.getGlobalBounds(); }

protected:
	sf::RectangleShape shape;

private:
	sf::Color color;

	int score = 0;
	unsigned int life = 1;

	float itemRate = 0.2f;
	Item* itemOnDestroy = nullptr;
};