#pragma once

#include "Item.h"

class Speeder : public Item
{
public:
	Speeder(const sf::Vector2f position);
	~Speeder() override;

	bool Start() override;

private:
	void Move(float deltaTime) override;
};