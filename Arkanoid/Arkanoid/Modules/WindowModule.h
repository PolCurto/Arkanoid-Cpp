#pragma once

#include "Module.h"

#include <memory>

namespace sf
{
	class Window;
}

class WindowModule : public Module
{
public:
	WindowModule();
	~WindowModule();

	bool Start() override;
	UpdateState Update() override;
	bool Close() override;

private:
	std::unique_ptr<sf::Window> window;
};