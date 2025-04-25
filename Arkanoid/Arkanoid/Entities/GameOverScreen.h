#pragma once

#include "Entity.h"

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>

namespace sf
{
	class Text;
}

class GameOverScreen : public Entity
{
public:
	GameOverScreen();
	~GameOverScreen();

	bool Start() override;
	UpdateState Update(float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState Draw() override;
	bool Close() override;

protected:
	sf::RectangleShape shape;

	sf::Font font;

	sf::Text* label;
};