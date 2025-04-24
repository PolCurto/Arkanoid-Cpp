#pragma once

#include "Block.h"

enum class PaddleMode
{
	Default,
	Large,
	Small
};

class Paddle : public Block
{
public:
	Paddle();
	~Paddle();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState Draw() override;
	bool Close() override;

	void Grow();
	void Shrink();

private:
	void GetInputs();
	void Move(const float deltaTime);
	void CheckEffects(const float deltaTime);
	void ResetSize();

private:
	sf::Color defaultColor = sf::Color({ 125, 125, 125 });
	float defaultWidth = 200.0f;

	float currentVelocity = 0;
	float velocity = 600;

	float effectDuration = 10;
	float timer = 0;
	PaddleMode mode = PaddleMode::Default;

};