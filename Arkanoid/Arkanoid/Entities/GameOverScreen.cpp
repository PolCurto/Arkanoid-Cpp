#include "GameOverScreen.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"

#include <SFML/Graphics/Text.hpp>


GameOverScreen::GameOverScreen() : Entity(EntityType::UI)
{
	if (font.openFromFile("HomeVideo-BLG6G.ttf"))
	{
		//TODO: Get all fonts from same place
		label = new sf::Text(font);
	}

	isEnabled = false;
}

GameOverScreen::~GameOverScreen()
{

}

bool GameOverScreen::Start()
{
	shape.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	shape.setFillColor(sf::Color(10, 10, 10));
	shape.setPosition({ 0, 0 });

	label->setString("          GAME OVER\nPress 'r' to go to main menu");
	label->setCharacterSize(48);
	label->setFillColor(sf::Color::Red);
	label->setPosition(sf::Vector2f(150, 400));

	return true;
}

UpdateState GameOverScreen::Draw()
{
	if (!isEnabled) return UPDATE_CONTINUE;

	App->renderer->DrawShape(shape);
	App->renderer->DrawText(*label);
	return UPDATE_CONTINUE;
}

bool GameOverScreen::Close()
{
	delete label;
	return true;
}