#include "GameModule.h"

#include "Entities/Ball.h"

GameModule::GameModule()
{
	entities.push_back(new Ball());
}

GameModule::~GameModule()
{

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

UpdateState GameModule::Update()
{
	UpdateState state = UPDATE_CONTINUE;

	// First update the entities' logic
	for (Entity* entity : entities)
	{
		state = entity->Update();
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
	return true;
}