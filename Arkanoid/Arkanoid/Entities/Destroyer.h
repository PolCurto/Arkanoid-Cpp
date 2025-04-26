#pragma once

#include "Item.h"

class Destroyer : public Item
{
public:
	Destroyer(const sf::Vector2f position) : Item(position) {};
	~Destroyer() override = default;

	bool Start() override;

private:
	void Move(float deltaTime) override;

private:
	float speedIncrease = 800;
};
