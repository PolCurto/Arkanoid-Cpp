#pragma once

#include "Module.h"

namespace sf
{
	class RenderWindow;
	class Shape;
	class Text;
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
	void DrawText(const sf::Text& text);

private:
	sf::RenderWindow* mainWindow;

};