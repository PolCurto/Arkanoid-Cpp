#pragma once

#include "Module.h"

namespace sf
{
	class RenderWindow;
	class Shape;
}

class RenderModule : public Module
{
public:
	RenderModule(sf::RenderWindow* window);
	~RenderModule();

	bool Start() override;
	UpdateState Update(const float deltaTime) override;
	UpdateState PostUpdate(const float deltaTime) override;
	bool Close() override;

	void DrawShape(const sf::Shape& shape);

private:
	sf::RenderWindow* mainWindow;

};