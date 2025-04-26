#pragma once

#include "Item.h"

class Destroyer : public Item
{
public:
	Destroyer(const sf::Vector2f position);
	~Destroyer() override;

	bool Start() override;

private:
	void Move(float deltaTime) override;

private:
	float speedIncrease = 800;
};
