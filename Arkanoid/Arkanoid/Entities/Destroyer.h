#pragma once

#include "Item.h"

class Destroyer : public Item
{
public:
	Destroyer(const sf::Vector2f position);
	~Destroyer();

	bool Start() override;

private:
	void Move(float deltaTime) override;
};
