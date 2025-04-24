#pragma once

#include "Module.h"

#include "Entities/Entity.h"

#include <vector>

class Ball;
class Paddle;

class GameModule : public Module
{
public:
	GameModule();
	~GameModule();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState PostUpdate(const float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	void OnMiss();
	void AddEntity(Entity* newEntity) { entitiesToAdd.push_back(newEntity); }
	void DeleteEntity(Entity* entity) { entitiesToDelete.push_back(entity); }

	const std::vector<Entity*>& GetAllEntities() const { return entities; }
	Paddle* GetPaddle() const { return paddle; }
	Ball* GetBall() const { return ball; }

private:
	void ManageEntities();

	Ball* ball;
	Paddle* paddle;

	std::vector<Entity*> entities;
	std::vector<Entity*> entitiesToAdd;
	std::vector<Entity*> entitiesToDelete;

	int score;
};