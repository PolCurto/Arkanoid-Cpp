#pragma once

#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Block : public Entity
{
public:
	Block();
	Block(const float x, const float y);
	Block(const EntityType type);
	~Block();

	virtual bool Start() override;
	virtual UpdateState Update(const float deltaTime) override;
	virtual UpdateState Draw() override;
	virtual bool Close() override;

	void OnHit(const int damage);

private:
	void Destroy();

protected:
	sf::RectangleShape shape;

	unsigned int life;
};