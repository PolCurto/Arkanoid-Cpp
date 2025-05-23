#pragma once

#include "Block.h"

class Bullet;

class Paddle : public Block
{
public:
	Paddle() : Block(EntityType::Paddle) {}
	~Paddle() override = default;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState Draw() const override;

	void SpeedUp();
	void AddGun();

private:
	void GetInputs(float deltaTime);
	void Move(float deltaTime);
	void CheckTimers(float deltaTime);
	void SetGunsPositions();
	void Shoot(float deltaTime);

private:
	sf::Color defaultColor = sf::Color( 125, 125, 125 );

	float currentVelocity = 0;
	float defaultVelocity = 600;
	float velocity = 0;

	bool isFast = false;
	float speederDuration = 10;
	float speedTimer = 0;

	bool hasGuns = false;
	float gunsDuration = 5;
	float gunsTimer = 0;
	float fireRate = 0.5f;
	float fireTimer = 0;

	sf::RectangleShape leftGun;
	sf::RectangleShape rightGun;

	std::vector<Bullet*> bullets;
	int bulletIndex = 0;
};