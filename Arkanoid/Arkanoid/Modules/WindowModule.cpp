#include "WindowModule.h"

#include <SFML/Window.hpp>

WindowModule::WindowModule()
{

}

WindowModule::~WindowModule()
{

}

bool WindowModule::Start()
{
	window = std::make_unique<sf::Window>();
	window->create(sf::VideoMode({ 800, 800 }), "Arkanoid");
	return true;
}

UpdateState WindowModule::Update()
{
	UpdateState state = UPDATE_CONTINUE;

	while (const std::optional event = window->pollEvent())
	{
		if (event->is<sf::Event::Closed>()) {
			window->close();
			state = UPDATE_STOP;
		}
	}
	return state;
}

bool WindowModule::Close()
{
	return true;
}