#include "TopPanel.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"

#include <SFML/Graphics/Text.hpp>


TopPanel::TopPanel() : Entity(EntityType::UI)
{
	if (font.openFromFile("HomeVideo-BLG6G.ttf"))
	{
		scoreLabel = new sf::Text(font);
		score = new sf::Text(font);
		lifeLabel = new sf::Text(font);
		life = new sf::Text(font);
	}
}

TopPanel::~TopPanel()
{

}

bool TopPanel::Start()
{
	shape.setSize(sf::Vector2f(SCREEN_WIDTH, TOP_PANEL_HEIGHT));
	shape.setFillColor({ 10, 10, 10 });
	shape.setPosition({ 0, 0 });

	scoreLabel->setString("SCORE");
	scoreLabel->setCharacterSize(40);
	scoreLabel->setFillColor(sf::Color::Red);
	scoreLabel->setPosition(sf::Vector2f(200, 25));

	score->setString("0");
	score->setCharacterSize(40);
	score->setFillColor(sf::Color::White);
	score->setPosition(sf::Vector2f(200, 70));

	lifeLabel->setString("LIVES");
	lifeLabel->setCharacterSize(40);
	lifeLabel->setFillColor(sf::Color::Red);
	lifeLabel->setPosition(sf::Vector2f(600, 25));

	life->setString("3");
	life->setCharacterSize(40);
	life->setFillColor(sf::Color::White);
	life->setPosition(sf::Vector2f(650, 70));

	return true;
}

UpdateState TopPanel::Draw()
{
	if (!isEnabled) return UPDATE_CONTINUE;

	App->renderer->Draw(shape, Layer::UI);
	App->renderer->Draw(*scoreLabel, Layer::UI);
	App->renderer->Draw(*score, Layer::UI);
	App->renderer->Draw(*lifeLabel, Layer::UI);
	App->renderer->Draw(*life, Layer::UI);
	return UPDATE_CONTINUE;
}

bool TopPanel::Close()
{
	delete scoreLabel;
	delete score;

	delete lifeLabel;
	delete life;

	return true;
}

void TopPanel::SetScore(int newScore, sf::Color color)
{
	score->setString(std::to_string(newScore));
	scoreLabel->setFillColor(color);
}

void TopPanel::SetLife(const int lives)
{
	life->setString(std::to_string(lives));
}