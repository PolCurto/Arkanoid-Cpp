#include "GameModule.h"

#include "Entities/Ball.h"
#include "Entities/Block.h"
#include "Entities/Paddle.h"
#include "Entities/TopPanel.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameModule::GameModule()
{
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
	if (isGameOver)
	{

	}
	else
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
	//TODO: Pantalla pausa maybe
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
	isGameOver = true;

	//TODO: ventana de game over press r to continue
}