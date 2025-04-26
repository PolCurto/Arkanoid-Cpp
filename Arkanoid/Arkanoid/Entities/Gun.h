#pragma once

#include "Item.h"

class Gun : public Item
{
public:
	Gun(const sf::Vector2f position) : Item(position) {};
	~Gun() override = default;

	bool Start() override;

private:
	void Move(float deltaTime) override;
};
