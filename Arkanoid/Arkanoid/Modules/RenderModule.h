#pragma once

#include "Module.h"

#include <SFML/Graphics/RectangleShape.hpp>

namespace sf
{
	class RenderWindow;
	class Shape;
	class Text;
}

enum class Layer
{
	Background = 0,
	Front,
	UI,
	Count
};

class RenderModule : public Module
{
public:
	RenderModule(sf::RenderWindow* window) : mainWindow(window) {}
	~RenderModule() override = default;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState PostUpdate(float deltaTime) override;
	bool Close() override { return true; }

	void Draw(const sf::Drawable& drawable, const Layer layer); 

private:
	sf::RenderWindow* mainWindow = nullptr;
	sf::RectangleShape background;

	std::vector<const sf::Drawable*> entitiesToDraw[(int)Layer::Count];
};