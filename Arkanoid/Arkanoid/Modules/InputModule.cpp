#include "InputModule.h"

#include "Application.h"
#include "GameModule.h"

#include <SFML/Graphics.hpp>

Globals::UpdateState InputModule::Update(float deltaTime)
{
	Globals::UpdateState state = Globals::UpdateState::Continue;

	while (const std::optional<sf::Event> event = mainWindow->pollEvent())
	{
		if (event->is<sf::Event::Closed>()) {
			state = Globals::UpdateState::Stop;
		}
		if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scan::Escape)
		{
			App->game->PauseGame();
		}
		if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scan::Enter)
		{
			App->game->StartGame();
		}
	}

	return state;
}

bool InputModule::IsKeyDown(sf::Keyboard::Scan key) const
{
	return sf::Keyboard::isKeyPressed(key);
}