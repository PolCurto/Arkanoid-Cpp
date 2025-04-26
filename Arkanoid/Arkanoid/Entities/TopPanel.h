#pragma once

#include "Entity.h"

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>

namespace sf
{
	class Text;
}

class TopPanel : public Entity
{
public:
	TopPanel();
	~TopPanel() override;

	bool Start() override;
	UpdateState Update(float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState Draw() override;
	bool Close() override;

	void SetScore(int newScore, sf::Color color = sf::Color::Red);
	void SetLife(const int lives);

protected:
	sf::RectangleShape shape;

	sf::Font font;

	sf::Text* scoreLabel;
	sf::Text* score;

	sf::Text* lifeLabel;
	sf::Text* life;
};