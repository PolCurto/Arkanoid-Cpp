#include "GameModule.h"

#include "Entities/Ball.h"
#include "Entities/Block.h"
#include "Entities/Paddle.h"

GameModule::GameModule()
{
	entities.push_back(new Ball());
	entities.push_back(new Block());
	entities.push_back(new Paddle());
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