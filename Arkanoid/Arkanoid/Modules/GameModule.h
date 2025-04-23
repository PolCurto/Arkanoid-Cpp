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
	UpdateState Update() override;
	UpdateState PostUpdate() override { return UPDATE_CONTINUE; };
	bool Close() override;

private:
	std::vector<Entity*> entities;

};