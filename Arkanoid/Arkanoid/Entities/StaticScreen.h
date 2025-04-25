#pragma once

#include "Entity.h"

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>

namespace sf
{
	class Text;
}

class StaticScreen : public Entity
{
public:
	StaticScreen();
	~StaticScreen();

	bool Start() override;
	UpdateState Update(float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState Draw() override;
	bool Close() override;

	void SetBackground(const sf::Color& color);
	void AddLabel(const std::string& text, const int size, const sf::Color& color, const sf::Vector2f& position);

protected:
	sf::RectangleShape shape;
	sf::Font font;
	std::vector<sf::Text*> labels;
};