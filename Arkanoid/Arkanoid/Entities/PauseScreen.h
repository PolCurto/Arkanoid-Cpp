#pragma once

#include "Entity.h"

#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>

namespace sf
{
	class Text;
}

class PauseScreen : public Entity
{
public:
	PauseScreen();
	~PauseScreen();

	bool Start() override;
	UpdateState Update(float deltaTime) override { return UPDATE_CONTINUE; };
	UpdateState Draw() override;
	bool Close() override;

protected:
	sf::RectangleShape shape;

	sf::Font font;

	sf::Text* pauseLabel;
};