#include "RenderModule.h"

#include <SFML/Graphics.hpp>

RenderModule::RenderModule(sf::RenderWindow* window) : mainWindow(window)
{

}

RenderModule::~RenderModule()
{

}

bool RenderModule::Start()
{
	return true;
}

UpdateState RenderModule::Update()
{
	//mainWindow->clear(sf::Color::Black);
	return UPDATE_CONTINUE;
}

UpdateState RenderModule::PostUpdate()
{
	mainWindow->display();
	return UPDATE_CONTINUE;
}

void RenderModule::DrawShape(const sf::Shape& shape)
{
	mainWindow->draw(shape);
}

bool RenderModule::Close()
{
	return true;
}