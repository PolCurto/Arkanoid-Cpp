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
	~WindowModule();

	bool Start() override;
	UpdateState Update(const float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState PostUpdate(const float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	sf::RenderWindow* GetWindow() { return window; }

private:
	sf::RenderWindow* window;
};