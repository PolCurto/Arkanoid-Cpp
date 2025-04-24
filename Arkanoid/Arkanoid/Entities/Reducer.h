#pragma once

#include "Item.h"

class Reducer : public Item
{
public:
	Reducer(const sf::Vector2f position);
	~Reducer();

	bool Start() override;

private:
	void Move(float deltaTime) override;
};
