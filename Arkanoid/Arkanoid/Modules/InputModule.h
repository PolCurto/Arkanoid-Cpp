#pragma once

#include "Module.h"

namespace sf 
{
	class RenderWindow;
}

class InputModule : public Module
{
public:
	InputModule(sf::RenderWindow* window);
	~InputModule();

	bool Start() override;
	UpdateState Update() override;
	UpdateState PostUpdate() override { return UPDATE_CONTINUE; };
	bool Close() override;

private:
	sf::RenderWindow* mainWindow;
};