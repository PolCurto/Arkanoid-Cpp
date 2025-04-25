#include "ResourcesModule.h"

#include <SFML/Audio.hpp>
#include <iostream>

ResourcesModule::ResourcesModule()
{

}

ResourcesModule::~ResourcesModule()
{

}

bool ResourcesModule::Start()
{
	// Load fonts
	sf::Font font;
	if (font.openFromFile("HomeVideo-BLG6G.ttf"))
	{
		fonts.insert({ "HomeVideo", font });
	}

	// Load audio files


	// Load textures
	


	return true;
}

UpdateState ResourcesModule::Update(float deltaTime)
{
	return UPDATE_CONTINUE;
}

bool ResourcesModule::Close()
{
	return true;
}