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
	RenderModule(sf::RenderWindow* window);
	~RenderModule() override;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override;
	Globals::UpdateState PostUpdate(float deltaTime) override;
	bool Close() override;

	void Draw(const sf::Drawable& drawable, const Layer layer); 

private:
	sf::RenderWindow* mainWindow;
	sf::RectangleShape background;

	std::vector<const sf::Drawable*> entitiesToDraw[(int)Layer::Count];
};