#pragma once

#include "Block.h"

class Paddle : public Block
{
public:
	Paddle();
	~Paddle();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState Draw() override;
	bool Close() override;

private:
	void GetInputs();
	void Move(const float deltaTime);

private:
	float currentVelocity = 0;
	float velocity = 500;
};