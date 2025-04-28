#pragma once

#include "Module.h"

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
	Globals::UpdateState Update(float deltaTime) override { return Globals::UpdateState::Continue; }
	Globals::UpdateState PostUpdate(float deltaTime) override { return Globals::UpdateState::Continue; }
	bool Close() override;

	sf::RenderWindow* GetWindow() const { return window; }

private:
	sf::RenderWindow* window = nullptr;
};