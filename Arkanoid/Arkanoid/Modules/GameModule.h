#pragma once

#include "Module.h"

#include "Entities/Entity.h"

#include <vector>

class GameModule : public Module
{
public:
	GameModule();
	~GameModule();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState PostUpdate(const float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

private:
	std::vector<Entity*> entities;

};