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
	Globals::UpdateState Draw() override;

	void SetScore(int newScore, sf::Color color = sf::Color::Red);
	void SetLife(const int lives);

protected:
	sf::RectangleShape shape;

	sf::Text* scoreLabel = nullptr;
	sf::Text* score = nullptr;
	sf::Text* lifeLabel = nullptr;
	sf::Text* life = nullptr;
};