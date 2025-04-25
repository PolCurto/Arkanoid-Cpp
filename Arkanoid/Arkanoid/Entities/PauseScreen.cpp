#include "PauseScreen.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"

#include <SFML/Graphics/Text.hpp>


PauseScreen::PauseScreen() : Entity(EntityType::UI)
{
	if (font.openFromFile("HomeVideo-BLG6G.ttf"))
	{
		//TODO: Get all fonts from same place
		pauseLabel = new sf::Text(font);
	}

	isEnabled = false;
}

PauseScreen::~PauseScreen()
{

}

bool PauseScreen::Start()
{
	shape.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	shape.setFillColor(sf::Color( 0, 0, 0, 150 ));
	shape.setPosition({ 0, 0 });

	pauseLabel->setString("     GAME PAUSED\nPress 'Esc' to resume");
	pauseLabel->setCharacterSize(48);
	pauseLabel->setFillColor(sf::Color::White);
	pauseLabel->setPosition(sf::Vector2f(150, 400));

	return true;
}

UpdateState PauseScreen::Draw()
{
	if (!isEnabled) return UPDATE_CONTINUE;

	App->renderer->DrawShape(shape);
	App->renderer->DrawText(*pauseLabel);
	return UPDATE_CONTINUE;
}

bool PauseScreen::Close()
{
	delete pauseLabel;

	return true;
}