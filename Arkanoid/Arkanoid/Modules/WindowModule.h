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
	~WindowModule() override;

	bool Start() override;
	UpdateState Update(float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState PostUpdate(float deltaTime) override { return UPDATE_CONTINUE; };
	bool Close() override;

	sf::RenderWindow* GetWindow() { return window; }

private:
	sf::RenderWindow* window;
};