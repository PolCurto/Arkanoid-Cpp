#pragma once

#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Item;

class Block : public Entity
{
public:
	Block(const sf::Vector2f position, const sf::Color color, const int score);
	Block(const EntityType type);
	virtual ~Block() override;

	virtual bool Start() override;
	virtual Globals::UpdateState Update(float deltaTime) override;
	virtual Globals::UpdateState Draw() override;
	virtual bool Close() override;

	void OnHit(const int damage);

	const sf::FloatRect GetBoundingBox() { return shape.getGlobalBounds(); };

private:
	void Destroy();

protected:
	sf::RectangleShape shape;

	sf::Color color;
	unsigned int life = 1;
	float itemRate = 0.2f;

	int score;
	Item* itemOnDestroy = nullptr;
};