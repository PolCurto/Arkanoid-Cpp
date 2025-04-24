#pragma once

#include "Item.h"

class Enlarger : public Item
{
public:
	Enlarger(const sf::Vector2f position);
	~Enlarger();

	bool Start() override;

private:
	void Move(float deltaTime) override;
};