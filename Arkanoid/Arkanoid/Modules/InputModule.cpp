#include "InputModule.h"

#include "Application.h"
#include "GameModule.h"

#include <SFML/Graphics.hpp>

InputModule::InputModule(sf::RenderWindow* window) : mainWindow(window)
{

}

InputModule::~InputModule()
{

}

bool InputModule::Start()
{
	return true;
}

UpdateState InputModule::Update(float deltaTime)
{
	UpdateState state = UPDATE_CONTINUE;


	while (const std::optional<sf::Event> event = mainWindow->pollEvent())
	{
		if (event->is<sf::Event::Closed>()) {
			state = UPDATE_STOP;
		}
		if (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->scancode == sf::Keyboard::Scan::Escape)
		{
			App->game->PauseGame();
		}
	}

	return state;
}

bool InputModule::Close()
{
	return true;
}

bool InputModule::IsKeyDown(sf::Keyboard::Scan key) const
{
	return sf::Keyboard::isKeyPressed(key);
}