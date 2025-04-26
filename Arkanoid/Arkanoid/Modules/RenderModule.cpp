#include "RenderModule.h"

#include "Application.h"
#include "ResourcesModule.h"

#include <SFML/Graphics.hpp>

bool RenderModule::Start()
{
	background.setPosition({ 0, Globals::TOP_PANEL_HEIGHT });
	background.setSize({ Globals::ARENA_WIDTH + (Globals::ARENA_H_BORDER * 2), Globals::ARENA_HEIGHT + Globals::ARENA_V_BORDER });
	background.setTexture(App->resources->GetTexture("background"));
	return true;
}

Globals::UpdateState RenderModule::Update(float deltaTime)
{
	mainWindow->clear(sf::Color({ 22, 28, 217 }));

	// Draw background texture
	Draw(background, Layer::Background);

	return Globals::UpdateState::Continue;
}

Globals::UpdateState RenderModule::PostUpdate(float deltaTime)
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

	return Globals::UpdateState::Continue;
}

void RenderModule::Draw(const sf::Drawable& drawable, const Layer layer)
{
	entitiesToDraw[(int)layer].push_back(&drawable);
}