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
	return true;
}

UpdateState RenderModule::Update(float deltaTime)
{
	mainWindow->clear(sf::Color({ 22, 28, 217 }));

	// Draw background texture
	Draw(background, Layer::Background);

	return UPDATE_CONTINUE;
}

UpdateState RenderModule::PostUpdate(float deltaTime)
{
	// Draw all entities by layers order
	for (int i = 0; i < (int)Layer::Count; ++i)
	{
		for (const sf::Drawable* entity : entitiesToDraw[i])
		{
			mainWindow->draw(*entity);
		}
		entitiesToDraw[i].clear();
	}
	mainWindow->display();

	return UPDATE_CONTINUE;
}

void RenderModule::Draw(const sf::Drawable& drawable, const Layer layer)
{
	entitiesToDraw[(int)layer].push_back(&drawable);
}
bool RenderModule::Close()
{
	return true;
}