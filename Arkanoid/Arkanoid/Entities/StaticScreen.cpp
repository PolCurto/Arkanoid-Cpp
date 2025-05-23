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
	for (sf::Text* label : labels)
	{
		delete label;
	}
	labels.clear();
}

bool StaticScreen::Start()
{
	shape.setSize(sf::Vector2f(Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT));
	shape.setPosition({ 0, 0 });
	return true;
}

Globals::UpdateState StaticScreen::Draw() const
{
	if (!isEnabled) return Globals::UpdateState::Continue;

	App->renderer->Draw(shape, Layer::UI);

	for (sf::Text* label : labels)
	{
		App->renderer->Draw(*label, Layer::UI);
	}
	return Globals::UpdateState::Continue;
}

void StaticScreen::SetBackground(const sf::Color& color)
{
	shape.setFillColor(color);
}

void StaticScreen::AddLabel(const std::string& text, const int size, const sf::Color& color, const sf::Vector2f& position)
{
	const sf::Font* font = App->resources->GetFont("HomeVideo");
	if (!font) return;

	sf::Text* newLabel = new sf::Text(*font);

	newLabel->setString(text);
	newLabel->setCharacterSize(size);
	newLabel->setFillColor(color);
	newLabel->setPosition(position);

	labels.push_back(newLabel);
}