#include "GameModule.h"

#include "Entities/Ball.h"
#include "Entities/Block.h"
#include "Entities/Paddle.h"
#include "Entities/TopPanel.h"
#include "Entities/StaticScreen.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameModule::GameModule()
{
	// Game entities
	entities.push_back(ball = new Ball());
	entities.push_back(paddle = new Paddle());

	const std::vector<sf::Color> colors = {
		sf::Color(143, 143, 143), sf::Color(255, 33, 33), sf::Color(255, 233, 33),
		sf::Color(31, 128, 255), sf::Color(229, 31, 255), sf::Color(74, 255, 38)
	};

	// Set all the blocks
	const uint8_t rows = 6;
	const uint8_t columns = 12;
	for (uint8_t x = 0; x < columns; ++x)
	{
		for (uint8_t y = 0; y < rows; ++y)
		{
			const sf::Vector2f position(x * 75.0f, y * 30.0f + 200.0f);
			entities.push_back(new Block(position, colors[y], (6 - y) * 10));
		}
	}

	entities.push_back(topPanel = new TopPanel());


	// Pause screen
	entities.push_back(pauseScreen = new StaticScreen());
	pauseScreen->SetBackground({ 0, 0, 0, 150 });
	pauseScreen->AddLabel("GAME PAUSED", 48, sf::Color::White, sf::Vector2f(285.0f, 300.0f));
	pauseScreen->AddLabel("Press 'esc' to resume", 36, sf::Color::White, sf::Vector2f(210.0f, 400.0f));

	// Game over screen
	entities.push_back(gameOverScreen = new StaticScreen());
	gameOverScreen->SetBackground({ 50, 0, 0 });
	gameOverScreen->AddLabel("GAME OVER", 80, sf::Color::Red, sf::Vector2f(230.0f, 300.0f));
	gameOverScreen->AddLabel("Press 'r' to restart", 36, sf::Color::White, sf::Vector2f(225.0f, 450.0f));

	// Start screen
	entities.push_back(startScreen = new StaticScreen());
	startScreen->SetBackground({ 0, 0, 50 });
	startScreen->AddLabel("ARKANOID", 80, sf::Color::Yellow, sf::Vector2f(260.0f, 300.0f));
	startScreen->AddLabel("Press enter to start", 36, sf::Color::White, sf::Vector2f(225.0f, 450.0f));
	startScreen->SetEnabled(true);
}

GameModule::~GameModule()
{
	for (Entity* entity : entities)
	{
		delete entity;
	}
	entities.clear();
}

bool GameModule::Start()
{
	bool state = true;

	for (Entity* entity : entities)
	{
		state = entity->Start();
		if (!state) break;
	}

	return state;
}

UpdateState GameModule::Update(float deltaTime)
{
	if (isPaused) deltaTime = 0;

	UpdateState state = UPDATE_CONTINUE;
	ManageEntities();

	// First update the entities' logic
	for (Entity* entity : entities)
	{
		state = entity->Update(deltaTime);
		if (state != UPDATE_CONTINUE) break;
	}

	if (state != UPDATE_CONTINUE) return state;

	// Draw them afterwards
	for (Entity* entity : entities)
	{
		state = entity->Draw();
		if (state != UPDATE_CONTINUE) break;
	}
	
	return UPDATE_CONTINUE;
}

bool GameModule::Close()
{
	bool state = true;

	for (Entity* entity : entities)
	{
		state = entity->Close();
		if (!state) break;
	}

	return state;
}

void GameModule::OnMiss()
{
	ball->Reset();

	// TODO: subtract score or something like that
	score -= 100;
	if (score < 0) score = 0;
	lives -= 1;

	if (lives == 0) EndGame();

	topPanel->SetScore(score);
	topPanel->SetLife(lives);
}

void GameModule::AddScore(int newScore)
{
	++streak;
	sf::Color color = sf::Color::Red;

	if (streak >= 5)
	{
		color = sf::Color(255, 175, 0);
		newScore *= 2;
	}
	if (streak >= 10)
	{
		color = sf::Color(175, 255, 0);
		newScore *= 2;
	}
	if (streak >= 20) 
	{
		color = sf::Color(0, 255, 75);
		newScore *= 2;
	}
	if (streak >= 40) 
	{
		color = sf::Color(0, 255, 200);
		newScore *= 2;
	}

	score += newScore;

	topPanel->SetScore(score, color);
}

void GameModule::PauseGame()
{
	isPaused = !isPaused;
	pauseScreen->SetEnabled(isPaused);
}

void GameModule::StartGame()
{
	if (isStarted) return;

	isPaused = false;
	isStarted = true;
	startScreen->SetEnabled(false);
}

void GameModule::ManageEntities()
{
	for (Entity* oldEntity : entitiesToDelete)
	{
		const auto& it = std::find(entities.begin(), entities.end(), oldEntity);
		if (it != entities.end())
		{
			(*it)->Close();
			delete *it;
			entities.erase(it);
		}
	}

	for (Entity* newEntity : entitiesToAdd)
	{
		entities.push_back(newEntity);
		newEntity->Start();
	}

	entitiesToDelete.clear();
	entitiesToAdd.clear();
}

void GameModule::EndGame()
{
	isPaused = true;
	gameOverScreen->SetEnabled(true);
}

