#pragma once

#include "Entity.h"

#include <SFML/Graphics/RectangleShape.hpp>

class Block : public Entity
{
public:
	Block();
	Block(const EntityType type);
	~Block();

	virtual bool Start() override;
	virtual UpdateState Update(const float deltaTime) override;
	virtual UpdateState Draw() override;
	virtual bool Close() override;

protected:
	sf::RectangleShape shape;
};