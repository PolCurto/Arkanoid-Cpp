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
	InputModule(sf::RenderWindow* window) : mainWindow(window) {}
	~InputModule() override = default;

	bool Start() override { return true; }
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState PostUpdate(float deltaTime) override { return Globals::UpdateState::Continue; }
	bool Close() override { return true; };

	bool IsKeyDown(sf::Keyboard::Scan key) const;

private:
	sf::RenderWindow* mainWindow = nullptr;
};