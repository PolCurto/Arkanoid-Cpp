#include "ResourcesModule.h"

#include <SFML/Audio.hpp>

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
	if (font.openFromFile("HomeVideo-BLG6G.ttf")) fonts.insert({ "HomeVideo", font });

	// Load audio files
	sf::SoundBuffer buffer;
	if (buffer.loadFromFile("Audio/paddleBounce.ogg")) audioBuffers.insert({ "paddleBounce", buffer });
	if (buffer.loadFromFile("Audio/wallBounce.ogg")) audioBuffers.insert({ "wallBounce", buffer });
	if (buffer.loadFromFile("Audio/blockHit.ogg")) audioBuffers.insert({ "blockHit1", buffer });
	if (buffer.loadFromFile("Audio/shrink.wav")) audioBuffers.insert({ "shrink", buffer });
	if (buffer.loadFromFile("Audio/grow.wav")) audioBuffers.insert({ "grow", buffer });
	if (buffer.loadFromFile("Audio/destroyer.wav")) audioBuffers.insert({ "destroyer", buffer });
	if (buffer.loadFromFile("Audio/gameOver.ogg")) audioBuffers.insert({ "gameOver", buffer });

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