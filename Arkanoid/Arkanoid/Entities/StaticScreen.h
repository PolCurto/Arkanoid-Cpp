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
	~StaticScreen() override;

	bool Start() override;
	Globals::UpdateState Update(float deltaTime) override { return Globals::UpdateState::Continue; };
	Globals::UpdateState Draw() override;
	bool Close() override;

	void SetBackground(const sf::Color& color);
	void AddLabel(const std::string& text, const int size, const sf::Color& color, const sf::Vector2f& position);

protected:
	sf::RectangleShape shape;
	std::vector<sf::Text*> labels;
};