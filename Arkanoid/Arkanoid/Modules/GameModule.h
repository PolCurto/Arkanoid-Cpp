#pragma once

#include "Module.h"

#include "Entities/Entity.h"

#include <vector>

class Ball;
class Paddle;
class TopPanel;
class PauseScreen;
class StaticScreen;

enum class GameState
{
	Start,
	Playing,
	Defeat,
	Victory
};

class GameModule : public Module
{
public:
	GameModule();
	~GameModule();

	bool Start() override;
	UpdateState Update(float deltaTime) override;
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	void OnMiss();
	void AddScore(int newScore);
	void PauseGame();
	void StartGame();

	void AddEntity(Entity* newEntity) { entitiesToAdd.push_back(newEntity); }
	void DeleteEntity(Entity* entity) { entitiesToDelete.push_back(entity); }
	const std::vector<Entity*>& GetAllEntities() const { return entities; }

	Paddle* GetPaddle() const { return paddle; }
	Ball* GetBall() const { return ball; }

private:
	void SetupScene();
	void ManageEntities();
	bool AreBlocksLeft();
	void EndGame();

	Ball* ball;
	Paddle* paddle;
	TopPanel* topPanel;

	StaticScreen* pauseScreen;
	StaticScreen* startScreen;
	StaticScreen* gameOverScreen;
	StaticScreen* victoryScreen;

	std::vector<Entity*> entities;
	std::vector<Entity*> entitiesToAdd;
	std::vector<Entity*> entitiesToDelete;

	int score = 0;
	int streak = 0;
	int lives = 3;

	GameState state = GameState::Start;
	bool isPaused = true;
};