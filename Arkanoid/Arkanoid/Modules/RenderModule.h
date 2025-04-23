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
	UpdateState Update() override;
	UpdateState PostUpdate() override;
	bool Close() override;

	void DrawShape(const sf::Shape& shape);

private:
	sf::RenderWindow* mainWindow;

};