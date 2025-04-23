#include "WindowModule.h"

#include "InputModule.h"

#include <SFML/Graphics.hpp>

WindowModule::WindowModule()
{
	window = new sf::RenderWindow();
}

WindowModule::~WindowModule()
{

}

bool WindowModule::Start()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;

	window->create(sf::VideoMode({ SCREEN_WIDTH, SCREEN_HEIGHT }), "Arkanoid", sf::Style::Default, sf::State::Windowed, settings);
	return true;
}

bool WindowModule::Close()
{
	window->close();
	delete window;
	return true;
}