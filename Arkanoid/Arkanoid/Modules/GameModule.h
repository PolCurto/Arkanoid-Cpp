#pragma once

#include "Module.h"

class GameModule : public Module
{
public:
	GameModule();
	~GameModule();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:

};