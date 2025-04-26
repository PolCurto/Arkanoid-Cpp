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
	~InputModule() override;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState PostUpdate(float deltaTime) override { return Globals::UpdateState::Continue; };
	bool Close() override;

	bool IsKeyDown(sf::Keyboard::Scan key) const;

private:
	sf::RenderWindow* mainWindow;
};