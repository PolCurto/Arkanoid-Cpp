#include "GameModule.h"

#include "Entities/Ball.h"
#include "Entities/Block.h"
#include "Entities/Paddle.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameModule::GameModule()
{
	entities.push_back(ball = new Ball());
	entities.push_back(new Paddle());

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
			entities.push_back(new Block(sf::Vector2f(x * 75, y * 30 + 60), colors[y]));
		}
	}
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

UpdateState GameModule::Update(const float deltaTime)
{
	UpdateState state = UPDATE_CONTINUE;

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
}