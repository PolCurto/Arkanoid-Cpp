#include "RenderModule.h"

#include "Application.h"
#include "ResourcesModule.h"

#include <SFML/Graphics.hpp>

RenderModule::RenderModule(sf::RenderWindow* window) : mainWindow(window)
{

}

RenderModule::~RenderModule()
{

}

bool RenderModule::Start()
{
	background.setPosition({ 0, TOP_PANEL_HEIGHT });
	background.setSize({ ARENA_WIDTH + (ARENA_H_BORDER * 2), ARENA_HEIGHT + ARENA_V_BORDER });
	background.setTexture(&App->resources->GetTexture("background"));

	DrawShape(background);
	return true;
}

UpdateState RenderModule::Update(float deltaTime)
{
	mainWindow->clear(sf::Color({ 22, 28, 217 }));

	// Draw background texture
	DrawShape(background);

	return UPDATE_CONTINUE;
}

UpdateState RenderModule::PostUpdate(float deltaTime)
{
	mainWindow->display();
	return UPDATE_CONTINUE;
}

void RenderModule::DrawShape(const sf::Shape& drawable)
{
	mainWindow->draw(drawable);
}

void RenderModule::DrawText(const sf::Text& text)
{
	mainWindow->draw(text);
}

bool RenderModule::Close()
{
	return true;
}