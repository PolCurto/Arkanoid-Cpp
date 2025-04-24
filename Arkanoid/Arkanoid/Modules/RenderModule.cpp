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

UpdateState RenderModule::Update(const float deltaTime)
{
	mainWindow->clear(sf::Color({ 22, 28, 217 }));
	return UPDATE_CONTINUE;
}

UpdateState RenderModule::PostUpdate(const float deltaTime)
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