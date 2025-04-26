#include "GameModule.h"

#include "Entities/Ball.h"
#include "Entities/Block.h"
#include "Entities/Paddle.h"
#include "Entities/TopPanel.h"
#include "Entities/StaticScreen.h"
#include "AudioModule.h"
#include "Application.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

GameModule::GameModule()
{
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
	SetupScene();

	bool state = true;

	for (Entity* entity : entities)
	{
		state = entity->Start();
		if (!state) break;
	}

	return state;
}

Globals::UpdateState GameModule::Update(float deltaTime)
{
	if (isPaused) deltaTime = 0;

	Globals::UpdateState state = Globals::UpdateState::Continue;
	ManageEntities();

	// First update the entities' logic
	for (Entity* entity : entities)
	{
		state = entity->Update(deltaTime);
		if (state != Globals::UpdateState::Continue) break;
	}

	if (state != Globals::UpdateState::Continue) return state;

	// Draw them afterwards
	for (Entity* entity : entities)
	{
		state = entity->Draw();
		if (state != Globals::UpdateState::Continue) break;
	}
	
	return Globals::UpdateState::Continue;
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

	topPanel->SetScore(score);
	topPanel->SetLife(lives);

	if (lives == 0)
	{
		state = GameState::Defeat;
		EndGame();
	}
	else
	{
		App->audio->PlaySFX("miss");
	}
}

void GameModule::AddScore(int newScore)
{
	++streak;
	sf::Color color = sf::Color::Red;

	App->audio->PlaySFX("blockHit");

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

	if (!AreBlocksLeft())
	{
		state = GameState::Victory;
		EndGame();
	}
}

void GameModule::PauseGame()
{
	isPaused = !isPaused;
	pauseScreen->SetEnabled(isPaused);
	if (isPaused) App->audio->PauseMusic();
	else App->audio->ResumeMusic();
}

void GameModule::StartGame()
{
	if (state != GameState::Start) return;

	App->audio->PlayMusic("Audio/levelMusic.wav");

	isPaused = false;
	state = GameState::Playing;
	startScreen->SetEnabled(false);
}

void GameModule::SetupScene()
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
	const uint8_t columns = 10;
	for (uint8_t x = 0; x < columns; ++x)
	{
		for (uint8_t y = 0; y < rows; ++y)
		{
			const sf::Vector2f position(x * 75.0f + 75.0f + Globals::ARENA_H_BORDER, y * 30.0f + Globals::TOP_PANEL_HEIGHT + Globals::ARENA_V_BORDER + 90);
			entities.push_back(new Block(position, colors[y], (6 - y) * 10));
		}
	}

	entities.push_back(topPanel = new TopPanel());

	// Pause screen
	entities.push_back(pauseScreen = new StaticScreen());
	pauseScreen->SetBackground({ 0, 0, 0, 200 });
	pauseScreen->AddLabel("GAME PAUSED", 48, sf::Color::White, sf::Vector2f(320.0f, 300.0f));
	pauseScreen->AddLabel("Press 'esc' to resume", 36, sf::Color::White, sf::Vector2f(245.0f, 400.0f));

	// Game over screen
	entities.push_back(gameOverScreen = new StaticScreen());
	gameOverScreen->SetBackground({ 30, 0, 0 });
	gameOverScreen->AddLabel("GAME OVER", 120, sf::Color::Red, sf::Vector2f(155.0f, 350.0f));

	// Victory screen
	entities.push_back(victoryScreen = new StaticScreen());
	victoryScreen->SetBackground({ 0, 30, 0 });
	victoryScreen->AddLabel("YOU WIN!", 120, sf::Color::Green, sf::Vector2f(200.0f, 350.0f));

	// Start screen
	entities.push_back(startScreen = new StaticScreen());
	startScreen->SetBackground({ 0, 0, 50 });
	startScreen->AddLabel("ARKANOID", 80, sf::Color::Yellow, sf::Vector2f(285.0f, 300.0f));
	startScreen->AddLabel("Press enter to start", 36, sf::Color::White, sf::Vector2f(259.0f, 450.0f));
	startScreen->SetEnabled(true);

	App->audio->PlayMusic("Audio/startScreen.wav");
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

bool GameModule::AreBlocksLeft()
{
	bool areLeft = false;

	for (Entity* entity : entities)
	{
		if (entity->GetType() == EntityType::Block && entity->IsEnabled()) areLeft = true;
	}

	return areLeft;
}

void GameModule::EndGame()
{
	App->audio->StopMusic();
	App->audio->StopAllSFX();
	for (Entity* entity : entities)
	{
		entity->SetEnabled(false);
	}
	isPaused = true;

	switch (state)
	{
	case GameState::Defeat:
		App->audio->PlaySFX("gameOver");
		gameOverScreen->SetEnabled(true);
		break;

	case GameState::Victory:
		App->audio->PlayMusic("Audio/victory.wav", false);
		victoryScreen->SetEnabled(true);
		break;
	}
}

