#include "WindowModule.h"

#include "InputModule.h"

#include <SFML/Graphics.hpp>

WindowModule::WindowModule()
{
	window = new sf::RenderWindow();
}

WindowModule::~WindowModule()
{
	delete window;
}

bool WindowModule::Start()
{
	sf::ContextSettings settings;
	settings.antiAliasingLevel = 8;

	window->create(sf::VideoMode({ Globals::SCREEN_WIDTH, Globals::SCREEN_HEIGHT }), "Arkanoid", sf::Style::Default, sf::State::Windowed, settings);
	return true;
}

bool WindowModule::Close()
{
	window->close();
	return true;
}