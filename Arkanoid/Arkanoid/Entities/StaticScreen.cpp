#include "StaticScreen.h"

#include "Application.h"
#include "RenderModule.h"
#include "GameModule.h"
#include "ResourcesModule.h"

#include <SFML/Graphics/Text.hpp>


StaticScreen::StaticScreen() : Entity(EntityType::UI)
{
	isEnabled = false;
}

StaticScreen::~StaticScreen()
{
}

bool StaticScreen::Start()
{
	shape.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	shape.setPosition({ 0, 0 });
	return true;
}

UpdateState StaticScreen::Draw()
{
	if (!isEnabled) return UPDATE_CONTINUE;

	App->renderer->DrawShape(shape);

	for (sf::Text* label : labels)
	{
		App->renderer->DrawText(*label);
	}
	return UPDATE_CONTINUE;
}

bool StaticScreen::Close()
{
	for (sf::Text* label : labels)
	{
		delete label;
	}

	labels.clear();
	return true;
}

void StaticScreen::SetBackground(const sf::Color& color)
{
	shape.setFillColor(color);
}

void StaticScreen::AddLabel(const std::string& text, const int size, const sf::Color& color, const sf::Vector2f& position)
{
	sf::Text* newLabel = new sf::Text(App->resources->GetFont("HomeVideo"));

	newLabel->setString(text);
	newLabel->setCharacterSize(size);
	newLabel->setFillColor(color);
	newLabel->setPosition(position);

	labels.push_back(newLabel);
}