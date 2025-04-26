#pragma once

#include "Module.h"

#include <memory>

namespace sf
{
	class RenderWindow;
}

class WindowModule : public Module
{
public:
	WindowModule();
	~WindowModule() override = default;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override { return Globals::UpdateState::Continue; };
	Globals::UpdateState PostUpdate(float deltaTime) override { return Globals::UpdateState::Continue; };
	bool Close() override;

	sf::RenderWindow* GetWindow() { return window; }

private:
	sf::RenderWindow* window;
};