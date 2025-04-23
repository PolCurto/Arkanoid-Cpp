#include "InputModule.h"

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

UpdateState InputModule::Update()
{
	UpdateState state = UPDATE_CONTINUE;

	while (const std::optional event = mainWindow->pollEvent())
	{
		if (event->is<sf::Event::Closed>()) {
			state = UPDATE_STOP;
		}
	}

	return state;
}

bool InputModule::Close()
{
	return true;
}