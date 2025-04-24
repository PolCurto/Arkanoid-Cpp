#pragma once

#include "Module.h"

#include <SFML/Window/Keyboard.hpp>

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
	UpdateState Update(float deltaTime) override;
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	bool IsKeyDown(sf::Keyboard::Scan key) const;

private:
	sf::RenderWindow* mainWindow;
};